#include <memory>
#include <iostream>

void delete_int(int *p)
{
    delete p;
}

int main(int argc, char const *argv[])
{
    auto p = std::make_unique<int>(12);
    std::cout << *p << std::endl;

    return 0;
}
