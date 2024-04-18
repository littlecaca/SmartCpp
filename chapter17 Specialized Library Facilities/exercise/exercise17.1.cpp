#include <vector>
#include <string>
#include <tuple>

int main(int argc, char const *argv[])
{
    // exercise17.1
    auto t = std::make_tuple(10, 20, 30);
    // exercise17.2
    typedef std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>> Item;
    Item i {"Blob", {"Alisa", "Luna"}, {"You", 12}};
    
    
    return 0;
}
