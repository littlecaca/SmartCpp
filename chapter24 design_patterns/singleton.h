#pragma once

#include <memory>

// 懒汉式静态单例模式
template <typename T> class Singleton {
public:
  static T &getInstance() {
    // C++11标准规定静态局部变量的初始化是线程安全的
    static T instance;
    return instance;
  }

protected:
  Singleton() = default;                            // 默认构造
  Singleton(const Singleton &) = delete;            // 拷贝构造
  Singleton &operator=(const Singleton &) = delete; // 复制构造
  virtual ~Singleton() = default;
};
