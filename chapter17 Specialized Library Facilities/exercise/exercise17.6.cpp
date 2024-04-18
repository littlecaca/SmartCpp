#include <algorithm>
#include <string>
#include <tuple>
#include <vector>
#include "..\..\chapter7 Classes\access_specifiers.h"


using namespace std;

typedef vector<Sales_data> StoreT;
typedef vector<StoreT> FilesT;

struct QueryResult
{
    QueryResult() = default;
    constexpr QueryResult(size_t _index, StoreT::const_iterator _it1, StoreT::const_iterator _it2) :
        index(_index), it1(_it1), it2(_it2) {}
    size_t index = -1;
    StoreT::const_iterator it1;
    StoreT::const_iterator it2;
};

typedef QueryResult MatchT;

vector<MatchT> findBook(const string &book, const FilesT &file)
{
    vector<MatchT> matchs;
    for (auto it = file.cbegin(); it != file.cend(); ++it)
    {
        auto res = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        if (res.first != res.second)
            matchs.push_back(QueryResult(it - file.cbegin(), res.first, res.second));
    }
    return matchs;
}

int main(int argc, char const *argv[])
{
    /* code */
    FilesT file = {{Sales_data("112"), Sales_data("113")},
                   {Sales_data("113"), Sales_data("114")}};
    auto res = findBook("113", file);
    for (auto &mat : res)
    {
        cout << mat.index << ": ";
        for (auto it1 = mat.it1, it2 = mat.it2; it1 != it2; ++it1)
            cout << it1->isbn() << " ";
        cout << endl;
    }
    cout << "DONE" << endl;
    return 0;
}
