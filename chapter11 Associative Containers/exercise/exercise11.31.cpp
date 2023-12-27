#include <algorithm>
#include <iostream>
#include <map>
#include <string>



int main(int argc, char const *argv[]) {
    std::multimap<std::string, std::string> authors = {
        {"Dive", "server"},
        {"Dive", "game designer"},
        {"Dive", "pianist"},
        {"Maria", "teacher"}};

    auto ret = authors.equal_range("Dive");
    authors.erase(ret.first, ret.second);
    auto ret2 = authors.equal_range("Musk");
    authors.erase(ret2.first, ret2.second);

    // std::for_each(authors.begin(), authors.end(),
    //     [](std::pair<const std::string, std::string> &p) {
    //         std::cout << p.first << " : " << p.second << std::endl;
    //     });

    std::for_each(authors.begin(), authors.end(),
                  [](decltype(*authors.begin()) p) {
                      std::cout << p.first << " : " << p.second << std::endl;
                  });

    return 0;
}
