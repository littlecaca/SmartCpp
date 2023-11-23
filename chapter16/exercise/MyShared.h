#pragma once

#include <memory>
#include <functional>

template <typename T>
class MyShared
{
public:
    MyShared() : tp(nullptr), cp(new size_t(1)), deleter(nullptr) {}
    MyShared(const MyShared<T> &shared) : tp(shared.tp), cp(shared.cp), deleter(nullptr)
    {
        ++(*cp);
    }
    MyShared(T *p, const std::function<void(T *)> &dt = nullptr)
        : tp(p), cp(new size_t(1)), deleter(dt) {}

    void swap(MyShared<T> &shared) noexcept
    {
        T *temp = tp;
        size_t *temp_cp = cp;        auto temp_d = deleter;
        tp = shared.tp;
        cp = shared.cp;
        deleter = shared.deleter;
        shared.tp = temp;
        shared.cp = cp;
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
        if (!(--*cp))
        {
            if (deleter != nullptr)
            {
                deleter(tp);
            }
            else 
            {
                delete tp;
            }
            delete cp;
        }
    }

    size_t use_count() const noexcept
    {
        return *cp;
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

private:
    T *tp;
    size_t *cp;
    std::function<void(T *)> deleter;
};
