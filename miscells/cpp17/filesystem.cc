#include <string>
#include <filesystem>
#include <iostream>
#include <iostream>
#include <fstream>

int main(int argc, char const *argv[])
{
    namespace fs = std::filesystem;
    fs::path pa = "./filesystem.cc";
    std::string line;
    if (fs::exists(pa))
    {
        std::ifstream ifs(pa);
        while (getline(ifs, line))
        {
            std::cout << line << "\n";
        }
    }
    return 0;
}
