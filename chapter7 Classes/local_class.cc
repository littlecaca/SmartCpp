#include <iostream>

using namespace std;
// ====================
//   局部类
// ===================
// 在C++中，可以在函数内部定义类或者结构体，这种类
// 被称为局部类，外部无法访问。局部类有着诸多限制：
// 1. 只能在函数内部访问，外部无法访问
// 2. 成员函数只能在类的内部定义
// 3. 不能有静态数据成员
// 4. 不能直接访问函数内的局部变量，但可以访问外部静态变量

int g_cnt = 3;

int main() {
    static int g_cnt2 = 4;

    class Foo {
    public:
        Foo(int& x) : x_(x) {}
        void print() {
            cout << x_ + g_cnt + g_cnt2 << endl;
        }
    private:
        int& x_;
    };

    int x = 12;
    Foo foo(x);
    foo.print();
    return 0;
}
