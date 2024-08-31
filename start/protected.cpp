#include <iostream>

using namespace std;

class Base
{
public:
    virtual void func2();
protected:
    void func();
    void func4();

private:
    void func3();

};

// 保护继承
class Derived : protected Base
{
public:
    void func2() override;
    
    virtual void func5();

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
