#include <iostream>
#include <utility>

using namespace std;

class Base
{
public:
    Base() {
        cout << "default constructor" << endl;
    }
    Base(const Base &) {

        cout << "copy constructor" << endl;
    }
    Base(Base &&) = delete;
    void print()
    {
        cout << "run" << endl;
    }
};

class Derive : public Base
{
public:
    using Base::Base;
    Derive(Derive &&) {}
};

int main(int argc, char const *argv[])
{
    Base b;
    // Base b;
    // Base b2 = std::move(b);
    // Base b3 = Base();
    // copy ellsion will not work here
    // Base b4{std::move(b)};
    // Base b5 = std::move(b);

    
    // b4.print();
    // Base b2(std::move(b));
    // Derive d;
    // std::move(d);
    return 0;
}
