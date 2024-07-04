#include <vector>
#include <type_traits>
#include <memory>
#include <list>

using std::uninitialized_fill_n;


int main(int argc, char const *argv[])
{
    // std::type_info<int>::
    std::vector<int> vi(12);
    uninitialized_fill_n(vi.begin(), 12, 12);
    std::list<int> il;
    il.sort();
    return 0;
}
