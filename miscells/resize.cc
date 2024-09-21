#include <iostream>
#include <vector>

int main(int argc, char const *argv[])
{
    std::vector<int> v1{1, 2, 3,};
    v1.resize(5, 88);
    for (auto n : v1)
    {
        std::cout << n << "\t";
    }
    std::cout << std::endl;
    return 0;
}

