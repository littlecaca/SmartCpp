#include <iostream>

using namespace std;

/**
 * Test this saying:
 * "
 * A declaration must exist even if we only call the friend from members of the
 * friendship granting class.
 * "
 * 
 * Result: True
 */

class Foo
{
    friend void print() { cout << "yes" << endl; }
public:
    void test() const 
    {
        // Foo::print();    // true dude!
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
