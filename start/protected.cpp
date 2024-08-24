#include <iostream>

using namespace std;

class Base
{
protected:
    void func();

};

// 保护继承
class Derived : protected Base
{
protected:
    void func()
    {
        cout << "yes" << endl;
    }
    

};

int main(int argc, char *argv[])
{
    Derived dd;
    // dd.func();
}
