#ifndef MYALLOCATOR_H
#define MYALLOCATOR_H

#include <new>
#include <cstddef>  // ptrdiff_t
#include <cstdlib>
#include <climits>
#include <iostream>

namespace MY
{
template <typename T>
inline T* _allocate(ptrdiff_t size, T*)
{
    std::set_new_handler(0);
    T *temp = (T*)::operator new((size_t)(size * sizeof(T)));
    if (temp == nullptr)
    {
        std::cerr << "Out of memory" << std::endl;
        exit(1);
    }
    return temp;
}

template <typename T>
inline void _deallocate(T *ptr)
{
    ::operator delete(ptr);
}

// 为什么不写一个原地emplace的
template <typename T1, typename T2>
inline void _construct(T1 *ptr, const T2 &value)
{
    new (ptr) T2(value);
}

template <typename T>
inline void _destroy(T *ptr)
{
    ptr->~T();
}


template <typename T>
class allocator
{
public:
    typedef T *         pointer;
    typedef T &         reference;
    typedef const T *   const_pointer;
    typedef const T &   const_reference;
    typedef size_t      size_type;
    typedef ptrdiff_t   difference_type;
    
    template <typename U>
    struct rebind
    {
        typedef allocator<U> other;
    };

    pointer address(reference x) const
    {
        return static_cast<pointer>(&x);
    }

    const_pointer const_address(const_reference x) const
    {
        return static_cast<const_pointer>(&x);
    }

    pointer allocate(size_type n, const void *hint= 0)
    {
        return _allocate((difference_type)n, (pointer)0);
    }

    void deallocate(T *ptr)
    {
        _deallocate(ptr);
    }

    void construct(pointer p, const T& x)
    {
        _construct(p, x);
    }

    void destroy(pointer p)
    {
        _destroy(p);
    }

    size_type max_size() const
    {
        return (size_type)(UINT_MAX / sizeof(T));
    }
};  // end of allocator

}   // end of namespace MY

#endif  // MY