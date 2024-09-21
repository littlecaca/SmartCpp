#include <future>
#include <iostream>
#include <exception>
#include <thread>

using namespace std;


int main(int argc, char const *argv[])
{
    std::future<int> res = std::async(launch::async, [] { return 32; });
    
    // 等待执行完毕
    res.wait();

    while (res.wait_for(chrono::seconds(1)) == future_status::timeout)
    {
        // 超时
        cout << "timeout" << endl;
    }

    try
    {
        // 阻塞直到任务完成
        int result = res.get();
        cout << result << endl;
    }
    catch (const exception &e)
    {
        cerr << "Main() " << e.what() << endl;
        return -1;
    }

    return 0;
}
