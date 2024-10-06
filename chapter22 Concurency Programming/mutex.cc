#include <thread>
#include <mutex>

std::mutex m1;

int main(int argc, char const *argv[])
{
    std::unique_lock<std::mutex> lock(m1);
    return 0;
}
