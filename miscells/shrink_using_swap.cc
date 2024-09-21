#include <iostream>
#include <vector>
#include <algorithm> // For std::swap
#include <deque>

int main() {
    // 创建一个包含 100 个元素的 vector
    std::vector<int> vec(100);
    std::cout << "Capacity before swap: " << vec.capacity() << std::endl;
    
    // 减少 vector 的大小
    vec.resize(10);
    std::cout << "Capacity after resizing: " << vec.capacity() << std::endl;
    
    // 使用 swap 技巧释放多余的内存
    std::vector<int>().swap(vec);
    std::cout << "Capacity after swap: " << vec.capacity() << std::endl;


    std::deque<int> d1{1, 2, 3};
    
    
    return 0;
}