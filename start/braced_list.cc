#include <unordered_map>
#include <utility>
#include <vector>
#include <iostream>

using namespace std;


// ==============================
//     花括号列表不代表任何类型
// ==============================
// 花括号列表本身不代表任何类型，但其经常被用作：
// 1. 初始化数组/结构体
// 2. 初始化initializer_list<T>
// 3. 容器类型的initializer_list参数
// 只有在具体的上下文中，编译器才能决定将其转换为具体的类型
// 所以不要将花括号列表作为完美转发的参数去构造对象，因为编译器
// 不知道其类型。

struct Foo {
    int x;
    int y;
};

int main() {
    vector<Foo> foos;
    unordered_map<int, pair<int, int>> um;
    // 
    // um.emplace(12, {12, 23});
    unordered_map<int, int> um2;
    // foos.emplace_back({12, 112});
    um2.emplace(12, 23);
    cout << foos.front().x << ", " << foos.front().y << endl;
    return 0;
}
