#include <iostream>

using namespace std;
class A
{ /* . . . */
public:
    virtual ~A() {}
};
class B : public A
{ /* . . . */
};
class C : public B
{ /* . . . */
};

int main(int argc, char const *argv[])
{
    A *pa = new C;
    cout << typeid(pa).name() << endl;
    C cobj;
    A &ra = cobj;
    cout << typeid(&ra).name() << endl;
    B *px = new C;
    B &ra1 = *px;
    cout << typeid(ra1).name() << endl;
    return 0;
}
