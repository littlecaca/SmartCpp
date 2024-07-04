#include <alloca.h>
#include <iostream>
#include <deque>
#include <memory>

/**
 * 在C++中，类模板的部分特化是允许的，但成员函数的部分特化不是直接支持的
 */
template <typename T>
struct Foo
{
    void myfunction();
};


// 完全特化
template <>
void Foo<int>::myfunction()
{
}

// 对模板类进行部分特化
template <typename T>
struct Foo<T *>
{
};

int main(int argc, char const *argv[])
{
    std::allocator<int> allo;
    return 0;
}
