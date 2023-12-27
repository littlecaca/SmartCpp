#pragma once

#include <iostream>
#include <memory>

template <typename T, typename Dx = std::default_delete<T>>
class MyUnique
{
public:
    MyUnique() : tp(nullptr), deleter(Dx()) {}
    MyUnique(T *p) : tp(p), deleter(Dx()) {}
    MyUnique(const MyUnique &) = delete;
    MyUnique(T *p, const Dx &dt) : tp(p), deleter(dt) {}

    ~MyUnique()
    {
        deleter(tp);
    }

    void swap(MyUnique &unique) noexcept
    {
        auto temp = tp;
        auto temp_d = deleter;
        tp = unique.tp;
        deleter = unique.deleter;
        unique.tp = temp;
        unique.deleter = deleter;
    }

    MyUnique &operator=(const MyUnique &) = delete;

    MyUnique &operator=(nullptr_t) noexcept
    {
        reset();
        return *this;
    }

    T *operator->() const noexcept
    {
        return get();
    }

    T &operator*() const noexcept
    {
        return *get();
    }

    T *get() const noexcept
    {
        return tp;
    }

    explicit operator bool() const noexcept
    {
        return get() != nullptr;
    }

    void reset(T *p, const Dx &dt)
    {
        if (tp != p)
        {
            deleter(tp);
            tp = p;
        }
        deleter = dt;
    }

    void reset(T *p = nullptr) noexcept
    {
        if (tp != p)
        {
            deleter(tp);
            tp = p;
        }
    }

    Dx &get_deleter() const noexcept
    {
        return deleter;
    }

private:
    T *tp;
    Dx deleter;
};