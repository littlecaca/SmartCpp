#include <functional>
#include <algorithm>
#include <set>
#include <vector>
#include <iostream>
#include <list>


int main(int argc, char const *argv[])
{
    std::vector<int> v1{1, 2, 5, 2, 3};
    std::set<int> s1(v1.begin(), v1.end());

    // std::list自带remove, remove_if, unique, 可以直接删除元素
    std::list<int> l1(v1.begin(), v1.end());
    l1.unique();
    l1.remove(2);
    for (auto n : l1)
    {
        std::cout << n << "\t";
    }
    std::cout << std::endl;

    // 而其它容器就必须借助std::remove + erase方法了
    auto it = std::remove(v1.begin(), v1.end(), 2);
    v1.erase(it, v1.end());

    for (auto n : v1)
    {
        std::cout << n << "\t";
    }
    std::cout << std::endl;

    return 0;
}
