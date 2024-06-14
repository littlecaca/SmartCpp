#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

int main(int argc, char const *argv[])
{
    std::vector<std::string> vs;
    std::cout << std::count_if(vs.begin(), vs.end(),
        std::mem_fn(&std::string::empty)) << std::endl;
    
    return 0;
}
