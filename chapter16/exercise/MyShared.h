#pragma once

#include <memory>
#include <functional>

class PointerCounter
{
public:
    PointerCounter() : ref_count(1), count(1) {}
    int ref_count;
    int count;
};


template <typename T>
class MyShared
{
public:

    // Aggregation
    MyShared() : tp(nullptr), counter(new PointerCounter), deleter(nullptr) {}
    MyShared(const MyShared<T> &shared) : tp(shared.tp), counter(shared.counter), deleter(nullptr)
    {
        ++counter->count;
        ++counter->ref_count;
    }
    MyShared(T *p, const std::function<void(T *)> &dt = nullptr)
        : tp(p), counter(new PointerCounter), deleter(dt) {}
    
    MyShared(T *p, PointerCounter *ct , const std::function<void(T *)> &dt = nullptr)
        : tp(p), counter(ct), deleter(dt) {
            ++counter->count;
            ++counter->ref_count;
    }

    void swap(MyShared<T> &shared) noexcept
    {
        T *temp = tp;
        PointerCounter *temp_c = counter;
        auto temp_d = deleter;
        tp = shared.tp;
        counter = shared.counter;
        deleter = shared.deleter;
        shared.tp = temp;
        shared.counter = temp_c;
        shared.deleter = temp_d;
    }

    // =======================================
    //  这里operator写错一个字母调试了半天，好气
    // =======================================
    MyShared<T> &operator=(MyShared<T> shared) noexcept
    {
        swap(shared);
        return *this;
    }

    ~MyShared<T>() noexcept
    {
        if (!--counter->ref_count)
        {
            if (deleter != nullptr)
            {
                deleter(tp);
            }
            else 
            {
                delete tp;
            }
        }
        if (!--counter->count)
        {
            delete counter;
        }
    }

    size_t use_count() const noexcept
    {
        return counter->ref_count;
    }

    T *get() const noexcept
    {
        return tp;
    }

    std::function<void(T *)> *get_deleter() const noexcept
    {
        return deleter;
    }

    explicit operator bool() const noexcept
    {
        return get() != nullptr;
    }

    void reset()
    {
        swap(MyShared<T>());
    }

    void reset(T *p, std::function<void(T *)> dt = nullptr)
    {
        swap(MyShared<T>(p, dt));
    }

    T *operator->() const noexcept
    {
        return tp;
    }

    T &operator*() const noexcept
    {
        return *tp;
    }

    bool unique() const noexcept
    {
        return use_count() == 1;
    }

    T *tp;
    PointerCounter *counter;
    std::function<void(T *)> deleter;
};
