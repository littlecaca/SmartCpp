#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

// ==========================
//      nth_element
// ==========================
// nth_element 的功能是让位置n存储排序后的处于此位置的元素
// 实现原理是quick select，与普通快速排序不同的是，
// 它通过基准元素将序列划分为两部分后，只会去继续计算其中一部分。
// 这使得其平均时间复杂度为O(n)。

// ==========================
//  可以练习一下手动实现
// ==========================

// Hoare分区方案
int partition(vector<int>& array, int l, int r) {
    int left = l - 1;
    int right = r + 1;
    int pivot = array[l];
    while (true) {
        do { ++left; } while (array[left] < pivot);
        do { --right; } while (array[right] > pivot);
        if (left >= right) {
            break;
        }
        swap(array[left], array[right]);
    }
    return right;
}

int quick_select(vector<int>& array, int l, int r, int k) {
    if (l == r) {
        return array[k];
    }
    auto tar = partition(array, l, r);
    if (k <= tar) {
        return quick_select(array, l, tar, k);
    } else {
        return quick_select(array, tar + 1, r, k);
    }
}

int nth_element(vector<int>& array, int k) {
    int n = array.size();
    return quick_select(array, 0, n - 1, k);
}

int test() {
    vector<int> nums{1, -1, -18, 18, 32};
    auto res = nth_element(nums, 4);
    cout << res << endl;
    return 0;
}


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

    cout << "test my own implement: " << endl;
    test();
    return 0;
}
