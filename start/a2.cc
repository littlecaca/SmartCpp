#include <iostream>

using namespace std;

class Base
{
public:
    void f1() { cout << "I am Base f1()" << endl; }
    virtual void f2() { cout << "I am Base f2()" << endl; }
};

class Derived : public Base
{
public:
    using Base::f1;
    void f1() { cout << "I am Derived f1()" << endl; }
    void f2() { cout << "I am Derived f2()" << endl; }
};

int main(int argc, char const *argv[])
{
    Derived d;
    d.Base::f1();

    Base *b = new Derived;
    b->f2();
    return 0;
}
