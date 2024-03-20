#ifndef SALE_H
#define SALE_H

#include <iostream>

template <class T> class Sale
{
public:
    void nothing(T t);
};

template <class T>
void Sale<T>::nothing(T t)
{
    std::cout << t << std::endl;
}


#endif