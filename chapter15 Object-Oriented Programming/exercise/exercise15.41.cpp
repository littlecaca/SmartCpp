#include <set>
#include <algorithm>
#include <iostream>
#include <string>
#include <memory>
#include <iterator>
#include "../TextQuery.h"
#include "../FileLoader.h"

/*
 * Reimplement with built-in pointers
 *
 */

// =====================
//      Query_base
// =====================
class Query_base
{
    friend class Query;

protected:
    using line_no = TextQuery::line_no;
    virtual ~Query_base() = default;

private:
    virtual QueryResult eval(const TextQuery &) const = 0;
    virtual std::string rep() const =   0;
};

// ==================
//      Query: UI
// ==================
class Query
{
    friend Query operator~(const Query &);
    friend Query operator|(const Query &, const Query &);
    friend Query operator&(const Query &, const Query &);

public:
    // Bound to a WordQuery
    Query(const std::string &);

    // Execute the query
    QueryResult eval(const TextQuery &query) const
    {
        return q->eval(query);
    }
    // Get the query string representation
    std::string rep() const
    {
        return q->rep();
    }

    ~Query();

    // Copy constructor
    Query(const Query &query) : q(query.q), use(query.use) { ++*use; }
    // Copy assignment
    Query &operator=(const Query &query);

private:
    Query(Query_base *query) : q(query), use(new size_t(1)) {}
    Query_base *q;
    std::size_t *use;
};

// Output Operator
std::ostream &operator<<(std::ostream &os, const Query &query)
{
    return os << query.rep();
}

// Destructor
Query::~Query()
{
    if (!--*use)
    {
        delete q;
        delete use;
    }
}

// Assignment operator
Query &Query::operator=(const Query &query)
{
    ++*query.use;
    if (--*use)
    {
        delete q;
        delete use;
    }
    q = query.q;
    use = query.use;
    return *this;
}

// ==================
//      WordQuery
// ==================
class WordQuery : public Query_base
{
    friend class Query;

    WordQuery(const std::string &word) : query_word(word) {}
    QueryResult eval(const TextQuery &t) const override
    {
        return t.query(query_word);
    }
    std::string rep() const override
    {
        return query_word;
    }
    std::string query_word;
};

// Define the Query constructor taking a string
inline Query::Query(const std::string &s) : q(new WordQuery(s)), use(new size_t(1)) {}

// ===============
//    NotQuery
// ===============
class NotQuery : public Query_base
{
    friend Query operator~(const Query &);

    NotQuery(const Query &q) : query(q) {}
    QueryResult eval(const TextQuery &) const override;
    std::string rep() const override
    {
        return "~" + query.rep() + "";
    }
    Query query;
};

inline Query operator~(const Query &operand)
{
    return new NotQuery(operand);
}

QueryResult NotQuery::eval(const TextQuery &q) const
{
    auto result = query.eval(q);
    auto lines = std::make_shared<std::set<line_no>>();
    auto beg = result.begin(), end = result.end();
    for (line_no n = 0; n != result.get_file()->size(); ++n)
    {
        if (beg == end || n != *beg)
            lines->insert(n);
        else
            ++beg;
    }
    return QueryResult(rep(), lines, result.get_file());
}

// =======================
//      BinaryQuery
// =======================
class BinaryQuery : public Query_base
{
protected:
    BinaryQuery(const Query &lhs, const Query &rhs, std::string s)
        : left_query(lhs), right_query(rhs), opSym(s) {}
    // Abstract class: does not define eval
    std::string rep() const override
    {
        return "(" + left_query.rep() + " " + opSym + " " + right_query.rep() + ")";
    }

    Query left_query, right_query;
    std::string opSym;
};

// ===================
//      AndQuery
// ===================
class AndQuery : public BinaryQuery
{
    friend Query operator&(const Query &, const Query &);

    AndQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "&") {}
    QueryResult eval(const TextQuery &) const override;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
    return new AndQuery(lhs, rhs);
}

QueryResult AndQuery::eval(const TextQuery &q) const
{
    auto left = left_query.eval(q), right = right_query.eval(q);
    auto lines = std::make_shared<std::set<line_no>>();
    std::set_intersection(left.begin(), left.end(), right.begin(),
                          right.end(), std::inserter(*lines, lines->begin()));
    return QueryResult(rep(), lines, left.get_file());
}

// ==================
//      OrQuery
// ==================
class OrQuery : public BinaryQuery
{
    friend Query operator|(const Query &, const Query &);

    OrQuery(const Query &lhs, const Query &rhs) : BinaryQuery(lhs, rhs, "|") {}
    QueryResult eval(const TextQuery &) const override;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
    return new OrQuery(lhs, rhs);
}

QueryResult OrQuery::eval(const TextQuery &q) const
{
    auto left = left_query.eval(q), right = right_query.eval(q);
    std::shared_ptr<std::set<line_no>> lines(new std::set<line_no>(left.begin(), left.end()));
    lines->insert(right.begin(), right.end());
    return QueryResult(rep(), lines, left.get_file());
}

// Test
int main(int argc, char const *argv[])
{
    std::ifstream infile("../sample.txt");
    if (infile)
    {
        TextQuery rq(infile, new SentenceLoader);
        Query q = Query("fiery") & Query("bird") | Query("wind") | Query("there");
        // Query q = Query("fierysad") | Query("adsdsd");
        std::cout << q.rep() << ":" << std::endl;
        QueryResult result = q.eval(rq);
        print(std::cout, result, rq.loader->sep);
    }
    else
    {
        std::cout << "Can not open the file" << std::endl;
        return -1;
    }
    return 0;
}
