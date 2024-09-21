#include <iostream>
#include <optional>

int main(int argc, char const *argv[])
{
    std::optional<int> opt1;
    std::optional<int> opt2 = 213;
    // 用了类似联合体的东东，存储在栈上
    if (opt1)
    {
        std::cout << *opt1 << std::endl;
    }

    if (opt2)
    {
        std::cout << *opt2 << std::endl;

    }
    return 0;
}
