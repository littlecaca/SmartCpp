#include "../class_features.h"
#include <iostream>

int main(int argc, char const *argv[])
{
    Screen myScreen(5, 25, '_');
    myScreen.move(4, 0).set('#').display(std::cout);
    std::cout << std::endl;
    myScreen.display(std::cout);
    std::cout << std::endl;
    return 0;
}
