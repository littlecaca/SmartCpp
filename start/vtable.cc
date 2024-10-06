#include <iostream>

/**
 * 结论：不论子类中是否重写或者定义了自己的虚函数，编译器都会为
 * 其生成一个（单继承）或者多个（多继承）虚函数表vtable，
 * 在子类对象中保存对应数量的虚表指针vptr
 */

class B1
{
public:
    virtual void func1() 
    {
        std::cout << "B1::func1()" << std::endl;
    };
};

class B2
{
public:
    virtual void func2() 
    {
        std::cout << "B2::func2()" << std::endl;
    };
};

class Derived : public B1, public B2 
{
public:
    // virtual void func3()
    // {
    //     std::cout << "Derived::func3()" << std::endl;
    // }
};

typedef void (*Func)();

int main(int argc, char const *argv[])
{
    B1 b;
    B2 b2;
    Derived d;
    Func *p1 = *(Func**)&b;
    Func *p2 = *(Func**)&b2;
    Func *pd1 = *(Func**)&d;
    Func *pd2 = *((Func**)&d + 1);

    std::cout << p1 << ", " << p2 << ", " << pd1 << ", " << pd2 << std::endl;

    (*p1)();
    (*p2)();
    (*pd1)();
    (*pd2)();

    return 0;
}
