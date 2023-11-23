#include <iostream>

class Base
{
public:
};

class Derived : public Base
{
public:
    Derived() {
        std::cout << "sda" << std::endl;
    }
    void print()
    {
        
        std::cout << i << std::endl;
    }
private:
    int i = 9;
};

int main(int argc, char const *argv[])
{
    Base b;
    Base &bb = b;
    const Base &bbb = Base();

    Base &d = Derived();
    
    int i = 2;
    int &ii = i;

    // These three have undefined behaviour
    reinterpret_cast<Derived &>(bb).print();
    static_cast<Derived *>(&b)->print();
    reinterpret_cast<Derived &>(const_cast<Base &>(bbb)).print();
    
    // This is OK
    static_cast<Derived &>(d).print();
    return 0;
}
