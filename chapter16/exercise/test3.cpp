#include <iostream>

int main(int argc, char const *argv[])
{
    const int &n = 3;
    const_cast<int &>(n) = 4;
    const int s = 0;
    const_cast<int &>(s) = 123;

    std::cout << n << std::endl;
    std::cout << s << std::endl;

    int *i = reinterpret_cast<int *>(0);
    if (i == nullptr)
    {
        std::cout << "yes" << std::endl;
    }
    return 0;
}
