#include <algorithm>
#include <iostream>
#include <memory>

int main(int argc, char const *argv[])
{
    std::allocator<int> allo;
    int cnt = 100;
    int *pa = allo.allocate(sizeof(int) * cnt);
    std::uninitialized_fill(pa, pa + cnt, 12);

    std::for_each(pa, pa + cnt, [](int a) { std::cout << a << " "; });
    std::cout << std::endl;
    
    return 0;
}
