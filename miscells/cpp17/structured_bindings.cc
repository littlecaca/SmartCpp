#include <utility>
#include <iostream>

// ===================
//   C++17 结构化绑定
// ===================

// 功能：将一个集合拆开赋值给指定的变量：
// auto [x, y, z] = obj;
// 针对三种场景，编译器有三种实现方式：
// 1. 如果对象是数组类型（原生数组类型），那么相当于引用obj[0], obj[1], obj[2]。
//    注意数组元素数量要和提供的变量数量对应上。
// 2. tuple-like类型，例如pair, tuple, array，以及用户自定义的元组类。
//    编译器会依赖以下的接口：
//    std::tuple_size<T>：告诉编译器有多少个元素
//    std::tuple_element<I, T>: 告诉编译器第I个元素的类型
//    get<I>(obj): 实际取出第I个元素
// 3. 结构体/类，如果obj是普通的struct或class，并且能够访问到其全部成员，则可以直接绑定。

struct Foo {
    int x;
    int y;
};

class Base {
public:
    int x;
    int y;
    double k;   
};

int main(int argc, char const *argv[])
{
    // 1. 数组类型
    int nums[]{1, 2, 3};
    auto [x1, y1, z1] = nums;

    // 2. tuple-like类型
    std::pair<int, int> p;
    std::tuple<int, double, long long> t1{12, 32.3, 123343423};

    auto [a, b] = p;
    auto [c, d, e] = t1;

    std::cout << a << "\t" << b << std::endl;
    std::cout << c << "\t" << d << "\t" << e << std::endl;

    // 3. 结构体/类
    Foo foo;
    Base base;
    auto [x2, y2] = foo;
    auto [x3, y3, z3] = base;
    return 0;
}
