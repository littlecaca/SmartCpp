#include <iostream>

using namespace std;


class Base 
{
public:
    virtual ~Base() {}
    virtual bool equal(const Base &) const = 0;
};

class Derivedd : public Base
{
public:
    virtual bool equal(const Base &) const;
};

// global function
bool operator==(const Base &lhs, const Base &rhs)
{
    return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

bool Derivedd::equal(const Base &rhs) const 
{
    auto &r = dynamic_cast<const Derivedd &>(rhs);
    // do the work to compare two Derivedd objects and return the result
    return true;
}

int main(int argc, char const *argv[])
{
    int arr[10];
    Derivedd d;
    Derivedd *dp = new Derivedd;
    Base *bp = new Derivedd;
    cout << typeid(arr).name() << endl;
    cout << typeid(Derivedd).name() << endl;
    cout << typeid(d).name() << endl;
    cout << typeid(Base).name() << endl;
    cout << typeid(dp).name() << endl;
    cout << typeid(bp).name() << endl;
    cout << typeid(*bp).name() << endl;

    return 0;
}
