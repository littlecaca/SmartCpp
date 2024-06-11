#include <typeinfo>
#include <iostream>

class A
{
public:
    virtual ~A() {} /* . . . */
};

class B : public A
{ /* . . . */
};

class C : public B
{ /* . . . */
};

class D : public B, public A
{ /* . . . */
};

int main(int argc, char const *argv[])
{
    A *pa = new C;
    try
    {
        C &rc = dynamic_cast<C &>(*pa);
    }
    catch (const std::bad_cast &e)
    {

    }

    return 0;
}
