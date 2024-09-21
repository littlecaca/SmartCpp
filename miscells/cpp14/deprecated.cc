#include <iostream>


[[deprecated("this funtion is too old")]]
void func()
{
    std::cout << "Ha? Am I too old?" << std::endl;
}

int main(int argc, char const *argv[])
{
    func();
    return 0;
}
