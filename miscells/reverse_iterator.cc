#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> v1{1, 2, 3, 4};
    auto ri = v1.rbegin();

    v1.insert(ri.base(), 5);
    // iterator become invalid

    ri = v1.rbegin();
    for (auto n : v1)
    {
        std::cout << n << "\t";
    }
    std::cout << std::endl;

    // std::cout << *ri.base() << std::endl;
    v1.erase(v1.end() - 1);
    // v1.erase(v1.end()); // Undefined behavior

    // std::cout << *ri.base() << std::endl;
    for (auto n : v1)
    {
        std::cout << n << "\t";
    }
    std::cout << std::endl;
    
    return 0;
}
