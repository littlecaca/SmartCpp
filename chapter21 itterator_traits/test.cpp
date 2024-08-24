#include <endian.h>
#include <stdint.h>
#include <iostream>

int main(int argc, char const *argv[])
{
    uint16_t port = 12;
    std::cout << htobe16(port) << std::endl;
    std::cout << "Hello" << std::endl;
    return 0;
}
