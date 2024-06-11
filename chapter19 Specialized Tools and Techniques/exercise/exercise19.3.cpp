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
    // (1)
    // A *pa = new C;
    // B *pb = dynamic_cast< B* >(pa);
    // (2)
    // B *pb = new B;
    // if (C *pc = dynamic_cast< C* >(pb))
    // {
    //     std::cout << "success" << std::endl;
    // }
    // else
    // {
    //     std::cout << "defeat" << std::endl;
    // }
    // (3)
    // A *pa = new D;
    // B *pb = dynamic_cast<B *>(pa);
    
    return 0;
}
