#include <algorithm>
#include <string>
#include <tuple>
#include <vector>
#include "..\..\chapter7 Classes\access_specifiers.h"


using namespace std;

typedef vector<Sales_data> StoreT;
typedef vector<StoreT> FilesT;
typedef tuple<size_t, pair<StoreT::const_iterator, StoreT::const_iterator>> MatchT;

vector<MatchT> findBook(const string &book, const FilesT &file)
{
    vector<MatchT> matchs;
    for (auto it = file.cbegin(); it != file.cend(); ++it)
    {
        auto res = equal_range(it->cbegin(), it->cend(), book, compareIsbn);
        if (res.first != res.second)
            matchs.push_back(make_tuple(it - file.cbegin(), make_pair(res.first, res.second)));
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
        cout << get<0>(mat) << ": ";
        for (auto it1 = get<1>(mat).first, it2 = get<1>(mat).second; it1 != it2; ++it1)
            cout << it1->isbn() << " ";
        cout << endl;
    }
    cout << "DONE" << endl;
    return 0;
}
