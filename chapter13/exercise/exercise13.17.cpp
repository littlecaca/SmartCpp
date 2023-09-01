#include <random>
#include <iostream>
#include <string>

struct numbered {
    // Default Constructor
    numbered() : mysn(rand()) { }
    // Copy Constructor
    numbered(const numbered &);
    int mysn;
};

numbered::numbered(const numbered &) : mysn(rand()) { }

void f(numbered &s) { std::cout << s.mysn << std::endl; }

int main(int argc, char const *argv[])
{
    numbered a, b = a, c = b;
    std::cout << a.mysn << std::endl
              << b.mysn << std::endl
              << c.mysn << std::endl;

    f(a); f(b); f(c);
    return 0;
}
