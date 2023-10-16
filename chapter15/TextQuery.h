#include <map>
#include <memory>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <iostream>
#include <fstream>
#include "FileLoader.h"

#define DISTANCE ('a' - 'A')

std::string &format_word(std::string &w1)
{
    if (std::ispunct(w1.back()))
        w1.erase(w1.end() - 1);
    for (auto &c : w1)
    {
        if (std::isalpha(c) && c < 'a')
            c += DISTANCE;
    }
    return w1;
}

std::string make_plural(size_t count, const std::string &word, const std::string &suffix)
{
    if (count > 1)
    {
        return word + suffix;
    }
    return word;
}

class QueryResult;

class TextQuery
{
public:
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &infile, FileLoader *);
    QueryResult query(const std::string &key) const;
    std::shared_ptr<FileLoader> loader;

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

// Constructor
TextQuery::TextQuery(std::ifstream &infile, FileLoader *file_loader = new LineLoader)
    : file(new std::vector<std::string>),
      loader(file_loader)
{
    file = loader->load(infile);
    for (size_t n = 0; n != file->size(); ++n)
    {
        std::stringstream line(file->at(n));
        std::string word;
        while (line >> word)
        {
            auto &lines = wm[format_word(word)];
            if (!lines) // the default initialization of std::shared_ptr will make it null
                lines.reset(new std::set<line_no>);
            lines->insert(n);
        }
    }
}

class QueryResult
{
    friend std::ostream &print(std::ostream &, const QueryResult &, const std::string &);

public:
    QueryResult(std::string s, std::shared_ptr<std::set<TextQuery::line_no>> p,
                std::shared_ptr<std::vector<std::string>> f)
        : sought(s), lines(p), file(f) {}

    std::set<TextQuery::line_no>::iterator begin() { return lines->begin(); }
    std::set<TextQuery::line_no>::iterator end() { return lines->end(); }
    std::shared_ptr<std::vector<std::string>> &get_file() { return file; }

private:
    std::string sought;
    std::shared_ptr<std::set<TextQuery::line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

QueryResult TextQuery::query(const std::string &key) const
{
    // Format the key word
    std::string sought = key;
    format_word(sought);

    static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);

    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, const QueryResult &qr, const std::string &sep = "line")
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << std::endl;
    for (auto num : *qr.lines)
        os << "\t(" << sep << " " << num + 1 << ") " << *(qr.file->begin() + num)
           << std::endl;
    return os;
}

void run_queries(std::ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        std::cout << "enter a word to check for, or enter q to exit: ";
        std::string cmd;
        if (!(std::cin >> cmd) || cmd == "q")
            break;
        print(std::cout, tq.query(cmd)) << std::endl;
    }
}
