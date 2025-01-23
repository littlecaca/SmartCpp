#include <mutex>
#include <shared_mutex>
#include <thread>

using std::shared_mutex;
using std::shared_timed_mutex;
using std::shared_lock;
using namespace std;

class ShareContent
{
public:
    void read()
    {
        shared_lock lock(mutex_);
        // ...
    }

    void write()
    {
        lock_guard lock(mutex_);

        // ...
    }

private:
    
    shared_mutex mutex_;
};
