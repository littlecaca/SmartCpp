#include <mutex>
#include <condition_variable>
#include <thread>

int main(int argc, char const *argv[])
{
    std::mutex m1;

    {
        std::unique_lock<std::mutex> guard(m1, std::defer_lock);

        
    }

    {
        std::lock_guard<std::mutex> guard(m1);
        // auto g2 = std::move(guard);
    }


    {
        std::condition_variable cond;
    }

    return 0;
}