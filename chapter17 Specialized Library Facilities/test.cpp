#include <iostream>
#include <fstream>

int main()
{
    std::ifstream f("myfile.txt");

    for (char c; f.get(c); )
        std::cout << f.tellg() << ' ';
    
    return 0;
}