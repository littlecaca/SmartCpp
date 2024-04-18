#include <memory>
#include <set>
#include <vector>
#include <string>
#include <tuple>

using namespace std;

typedef size_t line_no;

typedef tuple<string, shared_ptr<set<line_no>>, shared_ptr<vector<string>>> QueryResult;

