#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>
#include <iostream>

class IsBetween {
    size_t lower;
    size_t upper;
    bool limit;     // whether the upper edge is limited
  public:
    IsBetween(int l, int u) : lower(l), upper(u), limit(true) {
        if (u < 0)
            limit = false;
        else {
            if (lower > upper)
                throw std::runtime_error("lower edge is bigger than the upper edge");
        }
    }
    bool operator()(const std::string &s) const {
        if (limit) 
            return s.size() >= lower && s.size() <= upper;
        else
            return s.size() >= lower;
    }

    std::string range() const {
        return "(" + std::to_string(lower) + ", " + (limit ? std::to_string(upper) : "-1") + ")"; 
    }
};



int main(int argc, char const *argv[])
{
    std::ifstream input("input.txt");
    std::string word;
    int count = 0;
    int count_10_or_more = 0;
    int sum = 0;
    auto judge = IsBetween(1, 9);
    auto judge_10_or_more = IsBetween(10, -1);
    while (input >> word) {
        ++sum;
        if (judge(word))
            ++count;
        if (judge_10_or_more(word))
            ++count_10_or_more;
    }
    const char *output_options[] = {"word is in the range", "words are in the range"};

    std::cout << count << " of " << sum << " "
              << output_options[count > 1 ? 1 : 0] << " " << judge.range() << std::endl;

    std::cout << count_10_or_more << " of " << sum << " "
              << output_options[count > 1 ? 1 : 0] << " " << judge_10_or_more.range() << std::endl;
    return 0;
}
