#include <iostream>

class Something
{
    int m_x{};

public:
    Something(int x)
        : m_x{ x }
    {
        std::cout << "Normal constructor\n";
    }

    Something(const Something& s) = delete;

    void print() { std::cout << "Something(" << m_x << ")\n"; }
};

int main()
{
    // ok: prior to C++17, copy elision became mandatory in some cases
    // where an accessible copy constructor need not be available.
    Something s { Something { 5 } }; 

    // error: the copy constructor is deleted
    // Something s2{s};     
    s.print();

    return 0;
}