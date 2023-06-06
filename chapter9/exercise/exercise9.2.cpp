#include <list>
#include <deque>

using std::deque;
using std::list;



int main(int argc, char const *argv[])
{
    list<deque<int>> l1;
    l1.push_back(deque<int>(10, 3));

    return 0;
}
