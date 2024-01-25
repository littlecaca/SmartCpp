#include <iostream>
#include <string>
#include <utility>
#include <memory>


template <typename T, typename... Args>
inline
std::shared_ptr<T> make_shared(Args &&... args)
{
    return std::shared_ptr<T>(new T(
        std::forward<Args>(args)...
    ));
}

int main(int argc, char const *argv[])
{
    auto sp = make_shared<std::string>(5, 'd');
    std::cout << *sp << std::endl;
    return 0;
}
