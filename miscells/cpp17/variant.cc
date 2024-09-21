#include <string>
#include <variant>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::variant<int, double, std::string> v = "12131";
    // std::variant能够自动管理内部对象的构造和析构
    v = 12;
    
    // visit
    std::visit([](auto &&arg) {
        std::cout << arg << std::endl;
    }, v);

    // get
    int val = std::get<int>(v);
    std::cout << val << std::endl;

    val = std::get<0>(v);
    std::cout << val << std::endl;

    // get_if 异常安全
    if (int *p = std::get_if<int>(&v); p != nullptr)
    {
        std::cout << *p << std::endl;
    }

    return 0;
}
