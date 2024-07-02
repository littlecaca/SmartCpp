#pragma once

#include <memory>
#include "MyShared.h"
#include <string>

using namespace std;

/**
 * 非线程安全
 */
template <typename T>
class MyWeak
{
public:
    MyWeak() : tp(nullptr), counter(nullptr) {}
    MyWeak(const MyShared<T> &sha) : tp(sha.tp), counter(sha.counter), deleter(sha.deleter) {
        ++counter->count;
    }

    MyShared<T> lock() const noexcept
    {
        if (expired())
            return MyShared<T> ();
        return MyShared(tp, counter, deleter);
    }

    size_t use_count() const noexcept
    {
        return counter->ref_count;
    }

    bool expired() const noexcept
    {
        return !counter->ref_count;
    }

    ~MyWeak() noexcept
    {
        if (!--counter->count)
            delete counter;
    }

private:
    T *tp;
    PointerCounter *counter;
    std::function<void(T *)> deleter;
};

