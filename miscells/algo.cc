#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char const *argv[])
{
    std::vector<int> v1{1,-33, 43, 34, 213, 321, 244,43, -23};

    std::nth_element(v1.begin(), v1.begin() + 2, v1.end(), std::greater<int>());
    // std::nth_element(v1.begin(), )

    for (auto n : v1)
    {
        std::cout << n << "\t";
    }
    std::cout << std::endl;

    std::priority_queue<int, vector<int>, std::greater<int>> que;
    que.push(4);
    que.push(1);
    std::cout << que.top() << std::endl;
    return 0;
}
