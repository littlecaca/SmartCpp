#include <iostream>

using namespace std;

// ================================
//      auto与decltype的区别
// ================================
// auto和decltype都用于自动类型推断，区别是功能和用法有所不同。
// auto一般用于变量初始化时，推断等号后面的值的类型，并且默认会抛弃引用和top_level的const属性。
// decltype用于推断其参数的类型，会保留其参数的全部属性。
// 另外，auto还可用于声明尾置返回类型的函数签名，也可与new配合使用根据参数自动推断类型。

int main(int argc, char const *argv[])
{
    const char * const volatile word = "hello";
    char *c1 = nullptr;
    auto w = word;
    const auto &w2 = word;
    auto *w3 = word;
    const auto *w4 = c1;

    const int vi = 2;
    decltype(vi) v2 = 2;

    auto res = new auto(v2);

    cout << w << endl;
    cout << w2 << endl;
    cout << w3 << endl;
    return 0;
}
