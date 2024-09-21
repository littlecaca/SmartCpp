#include <string_view>
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string s("hello c++17");

    std::string_view sv(s);

    std::cout << sv << std::endl;
    return 0;
}
