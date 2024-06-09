#include <iostream>
#include <fstream>
#include "../../chapter15 Object-Oriented Programming/TextQuery.h"

int main(int argc, char const *argv[])
{
    std::ifstream infile("myfile.txt");
    chapter15::TextQuery query(infile);

    auto res = query.query("cannon");
    chapter15::print(std::cout, res);
    return 0;
}
