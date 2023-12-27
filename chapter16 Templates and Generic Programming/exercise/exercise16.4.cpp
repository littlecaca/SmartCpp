#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <iostream>

template <typename Iter, typename Val>
Iter myfind(Iter begin, Iter end, Val target)
{
    for (Iter i = begin; i != end; ++i)
    {
        if (*i == target)
        {
            return i;
        }
    }
    return end;
}

int main(int argc, char const *argv[])
{
    std::list<int> li{1, 2, 3, 5, 65, 455};
    std::vector<int> vi{34, 54, 32, 21, 34, 45};

    std::cout << (std::find(li.begin(), li.end(), 4) == li.end() ? "no" : "yes") << std::endl;
    std::cout << std::find(vi.begin(), vi.end(), 32) - vi.begin() << std::endl;
    std::cout << (myfind(li.begin(), li.end(), 4) == li.end() ? "no" : "yes") << std::endl;
    std::cout << myfind(vi.begin(), vi.end(), 32) - vi.begin() << std::endl;
    
    return 0;
}
