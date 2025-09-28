#include <iostream>
#include <cstddef>
#include <tuple>
#include <type_traits>
#include <utility>

using namespace std;

struct MyTuple {
    int x;
    double y;
    float z;
    
    MyTuple() : x(0), y(0.0), z(0.0f) {}
    MyTuple(int x, double y, float z) : x(x), y(y), z(z) {}
};

// 标准库特化
namespace std {
    template<>
    struct tuple_size<MyTuple> : integral_constant<size_t, 3> {};
    
    template<> 
    struct tuple_element<0, MyTuple> { using type = int; };
    template<> 
    struct tuple_element<1, MyTuple> { using type = double; };
    template<> 
    struct tuple_element<2, MyTuple> { using type = float; };
}

// get 函数放在全局命名空间，让 ADL 能找到
template<size_t I>
constexpr auto get(MyTuple& obj) -> std::tuple_element_t<I, MyTuple>&;

template<>
constexpr auto get<0>(MyTuple& obj) -> int& {
    return obj.x;
}
template<>
constexpr auto get<1>(MyTuple& obj) -> double& {
    return obj.y;
}
template<>
constexpr auto get<2>(MyTuple& obj) -> float& {
    return obj.z;
}

// const 引用版本
template<size_t I>
constexpr auto get(const MyTuple& obj) -> const std::tuple_element_t<I, MyTuple>&;

template<>
constexpr auto get<0>(const MyTuple& obj) -> const int& {
    return obj.x;
}
template<>
constexpr auto get<1>(const MyTuple& obj) -> const double& {
    return obj.y;
}
template<>
constexpr auto get<2>(const MyTuple& obj) -> const float& {
    return obj.z;
}

// 右值引用版本
template<size_t I>
constexpr auto get(MyTuple&& obj) -> std::tuple_element_t<I, MyTuple>&&;

template<>
constexpr auto get<0>(MyTuple&& obj) -> int&& {
    return std::move(obj.x);
}
template<>
constexpr auto get<1>(MyTuple&& obj) -> double&& {
    return std::move(obj.y);
}
template<>
constexpr auto get<2>(MyTuple&& obj) -> float&& {
    return std::move(obj.z);
}

// const 右值引用版本
template<size_t I>
constexpr auto get(const MyTuple&& obj) -> const std::tuple_element_t<I, MyTuple>&&;

template<>
constexpr auto get<0>(const MyTuple&& obj) -> const int&& {
    return std::move(obj.x);
}
template<>
constexpr auto get<1>(const MyTuple&& obj) -> const double&& {
    return std::move(obj.y);
}
template<>
constexpr auto get<2>(const MyTuple&& obj) -> const float&& {
    return std::move(obj.z);
}

int main() {
    // 测试左值引用版本
    MyTuple node1(12, 12.12, 123.3f);
    auto [x1, y1, z1] = node1;
    cout << "Left value: " << x1 << ", " << y1 << ", " << z1 << endl;
    
    // 测试右值引用版本
    auto [x2, y2, z2] = MyTuple(42, 3.14, 2.71f);
    cout << "Right value: " << x2 << ", " << y2 << ", " << z2 << endl;
    
    // 测试const版本
    const MyTuple node3(100, 200.5, 300.7f);
    auto [x3, y3, z3] = node3;
    cout << "Const: " << x3 << ", " << y3 << ", " << z3 << endl;
    
    // 测试直接调用get函数
    MyTuple node4(1, 2.5, 3.7f);
    cout << "Direct get calls: " << get<0>(node4) << ", " 
         << get<1>(node4) << ", " << get<2>(node4) << endl;
    
    return 0;
}
