#include <iostream>
#include <string>

// =================================================
//   Argument Matching and Mutual Conversions
// =================================================

struct B;
struct A {
    A() = default;
    A(const B &) : A() {
        std::cout << "A's converting constructors" << std::endl;
    }
};

struct B {
    operator A() { 
        std::cout << "B's conversion operator" << std::endl;
        return A(); 
    }
};

A f(const A&) { return A(); }


// =============================================================
//   Ambiguities and Multiple Conversions to Built-in Types
// =============================================================

struct C
{
    C(long long = 0) {}
    C(double) {}
    operator short() const { return 1; }
    operator double() const {return 0.5; }
};

void f2(int) {}

int main(int argc, char const *argv[])
{
    B b;
    // ambiguous conversion
    // but ok, the B's conversion operator will be called
    A a = f(b);

    C c;
    f2(c);

    int lg;
    // error
    // C c2(lg);

    return 0;
}
