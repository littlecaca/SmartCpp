#pragma once

#include <memory>
#include <atomic>
#include <mutex>

template <typename T>
class Singleton
{
public:
    static T &getInstance()
    {
        // C++11标准规定静态局部变量的初始化是线程安全的
        static std::unique_ptr<T> instance(new T());
        return *instance;
    }

protected:
    Singleton() = default;
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
    virtual ~Singleton() = default;
};
