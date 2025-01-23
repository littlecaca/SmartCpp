#include <vector> 
#include <atomic>
#include <iostream> 
#include <thread>
#include <chrono>

// 
#define USE_SPINLOCK

class SpinLock
{
public:
    SpinLock() {}
    SpinLock(const SpinLock &) = delete;
    SpinLock &operator=(const SpinLock &) = delete;

    void lock()
    {
        while (flag.test_and_set(std::memory_order_acquire))
        {
            std::this_thread::yield();
        }
    }

    void unlock()
    {
        flag.clear(std::memory_order_release);
    }

private:
    std::atomic_flag flag;
};

SpinLock lock;
int num;
std::atomic_bool fence;  // 保证所有线程几乎同时运行

void increase()
{
    while (!fence.load(std::memory_order_acquire))
        std::this_thread::yield();

    for (int i = 0; i < 10000; ++i)
    {
#ifdef USE_SPINLOCK
        lock.lock();
#endif
        ++num;

#ifdef USE_SPINLOCK    
        lock.unlock();
#endif
        std::this_thread::yield();
    }
}

int main(int argc, char const *argv[])
{
    std::thread t1(increase);
    std::thread t2(increase);
    std::thread t3(increase);

    fence.store(true, std::memory_order_release);

    t3.join();
    t2.join();
    t1.join();

    std::cout << "Expected: 30000\n" << "Output: " <<
        num << std::endl;
    return 0;
}
