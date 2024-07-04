#include <iostream>

// 模板函数1：整型参数
template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type
display(T value) {
    std::cout << "Integer: " << value << std::endl;
}

// 模板函数2：浮点型参数
template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type
display(T value) {
    std::cout << "Floating point: " << value << std::endl;
}

int main() {
    display(42);         // 调用模板函数1
    display(3.14);       // 调用模板函数2

    return 0;
}
