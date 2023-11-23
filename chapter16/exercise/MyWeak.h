#pragma once

#include <memory>
#include "MyShared.h"
#include <string>

using namespace std;


template <typename T>
class MyWeak
{
public:
    MyWeak() : sp(nullptr) {}
    MyWeak(const MyShared<T> &sha) : sp(&sha) {}

    MyShared<T> lock() const noexcept
    {
        if (!expired())
            return MyShared<T> ();
        return *sp;
    }

    size_t use_count() const noexcept
    {
        if (sp == nullptr)
            return 0;
        return sp->use_count();
    }

    bool expired() const noexcept
    {
        return sp != nullptr && !*sp;
    }

    

private:
    const MyShared<T> *sp;
};

