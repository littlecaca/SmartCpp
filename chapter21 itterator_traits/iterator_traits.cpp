#include <iostream>

// ------------------------------------------------------
// c++11
template <typename T>
inline auto func(T iter) -> decltype(*iter)
{

}

// ------------------------------------------------------
// before c++11, except the original pointer
template <typename T>
inline typename T::value_type
func2(T iter)
{

}

// ------------------------------------------------------
// before c++11, utilizing the traits
template <typename T>
struct iterator_traits
{
    typedef typename T::value_type value_type;
};

// partial specification for original pointer
template <typename T>
struct iterator_traits<T*>
{
    typedef T value_type;
};

// partial specification for const original pointer
template <typename T>
struct iterator_traits<const T*>
{
    typedef T value_type;
};


template <typename T>
inline typename iterator_traits<T>::value_type
func3(T iter)
{

}
