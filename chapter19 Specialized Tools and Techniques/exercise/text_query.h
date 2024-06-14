#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

using std::cin;
using std::count;
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::make_shared;
using std::map;
using std::ostream;
using std::set;
using std::shared_ptr;
using std::string;
using std::vector;

using namespace std;

#define DISTANCE ('a' - 'A')


class TextQuery
{
public:
    class QueryResult;
    using line_no = vector<string>::size_type;
    TextQuery(ifstream &infile);
    QueryResult query(const string &key) const;

private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

class TextQuery::QueryResult
{
    friend ostream &print(ostream &, const QueryResult &);

public:
    QueryResult(string s, shared_ptr<set<TextQuery::line_no>> p,
                shared_ptr<vector<string>> f)
        : sought(s), lines(p), file(f) {}

    set<TextQuery::line_no>::iterator begin() { return lines->begin(); }
    set<TextQuery::line_no>::iterator end() { return lines->end(); }
    shared_ptr<vector<string>> &get_file() { return file; }

private:
    string sought;
    shared_ptr<set<TextQuery::line_no>> lines;
    shared_ptr<vector<string>> file;
};
#endif