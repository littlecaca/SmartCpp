#include <string>
#include <iostream>
#include <functional>

using namespace std;

class Foo
{
public:
    void func1(int)
    {
        cout << "func1(int)" << endl;
    }

    void func1(string)
    {
        cout << "func2(string)" << endl;
    }

    void func2(int)
    {
        cout << "func2(int)" << endl;
    }
};

int main(int argc, char const *argv[])
{
    Foo foo;
    // 如果成员函数被重载，
    // 需要先用一个指向成员函数的指针指定具体的函数
    void (Foo::*f1)(int) = &Foo::func1;

    function<void(Foo *, int)> f2 = f1;
    f2(&foo, 12);
    return 0;
}


