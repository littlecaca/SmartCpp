#include <iostream>
#include "Sale.h"

template <class T>
void Sale<T>::nothing(T t)
{
    std::cout << t << std::endl;
}

template class Sale<int>;
