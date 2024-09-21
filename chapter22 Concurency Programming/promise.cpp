#include <thread>
#include <iostream>
#include <future>

using namespace std;

int main(int argc, char const *argv[])
{
    promise<int> pro;
    future<int> fut = pro.get_future();

    thread([p = std::move(pro)]() mutable { p.set_value(22); }).detach();

    cout << fut.get() << endl;

    return 0;
}
