#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>

using namespace std::placeholders;

int main(int argc, char const *argv[])
{
    std::vector<int> vi{1, 2, 43, 4564, 2342, 123, 213, 21432};
    std::vector<std::string> vs{"you", "are", "really", "pooh"};
    size_t n = std::count_if(vi.begin(), vi.end(), std::bind(std::greater<int>(), _1, 1024));
    std::cout << n << " nums are greater than 1024" << std::endl;

    const auto target = std::find_if(vs.begin(), vs.end(), std::bind(std::not_equal_to<std::string>(), _1, "pooh"));
    std::cout << *target << std::endl;

    std::transform(vi.begin(), vi.end(), vi.begin(), std::bind(std::multiplies<int>(), _1, 2));
    for (auto i : vi)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
