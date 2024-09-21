#include <vector>
#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string s1 = "nihao";
    std::string s3 = "I am fine";

    std::string bigs1 = "yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy";
    std::string bigs2 = "OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO";

    std::vector<char> s2 = {'n', 'i', 'h', 'a', 'o', '\0'};
    std::vector<char> s4 = {'I', ' ', 'a', 'm', ' ', 'f', 'i', 'n', 'e', '\0'};

    auto it1 = s1.begin() + 2;
    auto it2 = s2.begin() + 2;
    auto it3 = bigs1.begin() + 2;
    s1.swap(s3);
    s2.swap(s4);
    bigs1.swap(bigs2);
    std::cout << *it1 << std::endl;
    std::cout << *it2 << std::endl;
    std::cout << *it3 << std::endl;
    return 0;
}
