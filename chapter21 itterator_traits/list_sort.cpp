#include <iomanip>
#include <iostream>
#include <list>
#include <vector>
#include <exception>

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::list<T> &rhs)
{
    for (const T &node : rhs)
        os << node << " ";
    return os;
}

/**
 * A stable and efficient sort algorithm for list
 */
template<typename T, typename Compare = std::less<T>>
void merge_sort(std::list<T>& lst, Compare comp = Compare()) {
    if (lst.empty()) return;

    int fill = 0;

    std::list<T> carry;
    std::list<T> counter[64];
    while (!lst.empty())
    {
        carry.splice(carry.begin(), lst, lst.begin());
        int i = 0;
        while (i < fill && !counter[i].empty())
        {
            counter[i].merge(carry);
            // std::cout << carry << std::endl;
            carry.swap(counter[i++]);
        }
        carry.swap(counter[i]);
        if (i == fill) ++fill;

        for (int i = 0; i < fill; ++i)
            std::cout << counter[i] << "|";
        std::cout << std::endl;
    }

    for (int i = 1; i < fill; ++i)
        counter[i].merge(counter[i - 1]);
    swap(lst, counter[fill - 1]);
}


int main() {
    std::list<int> my_list = {3, 1, 4, 1, 5, 9, 2, 6, 5};

    merge_sort(my_list);

    for (const auto& elem : my_list) {
        std::cout << elem << " ";
    }

    return 0;
}
