#include <iostream>
#include <algorithm>
#include <array>

class IsEqual {
  public:
    IsEqual(int i) : given(i) {}
    bool operator()(int i) const {
        return i == given;
    }
  private:
    int given;
};

int main(int argc, char const *argv[])
{
    std::array<int, 10> nums = {1, 2, 3, 4, 5, 6, 7, 7, 6, 5};
    std::replace_if(nums.begin(), nums.end(), IsEqual(5), -1);
    for (const auto n : nums) {
        std:: cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
