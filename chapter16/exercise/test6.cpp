#include <string>
#include "T1.h"
#include <iostream>

template class T1<std::string>;

int f()
{
    T1<std::string> t;
}
