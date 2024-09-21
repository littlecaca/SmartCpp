#include <iostream>
#include <semaphore>
#include <chrono>
#include <thread>

using namespace std;

std::binary_semaphore bs(1);
std::counting_semaphore cs(122);

void Thread()
{
    this_thread::sleep_for(std::chrono::seconds(1));
    cout << "Thread()" << endl;
    bs.release();
}

int main(int argc, char const *argv[])
{
    thread t(Thread);
    bs.acquire();
    cout << "main()" << endl;
    t.join();
    return 0;
}
