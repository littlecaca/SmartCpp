

#include <condition_variable>
#include <vector>
class Poller
{
public:
    const vector<Event> &Poll()
    {
        int ret = epoll_wait(epfd_, event_list_, events_size_,  0);
        if (ret == -1)
        {
            // 异常
        }

        if (ret == events_size_)
        {
            event_list_.resize(events_size_ * 2);
            events_size_ *= 2;
        }

        return ChangeToEvent(event_list_);
    } 

    void AddEvent(const Event *e, int event)
    {
        events_[e->fd] = e;
    }

    void DeleteEvent(const Event *)
    {
        // epoll_delete
        // events_.erase
    }

    void UpdateEvent(const Event *, int event)
    {

    }

    // 根据events_将系统库中的struct event转换为Event对象
    const vector<Event> &ChangeToEvent(const  vector<struct event *> &);

private:
    vector<struct event *> event_list_;
    int events_size_;
    int epfd_;
    unordered_map<int, Event *> events_;
};

class EventHandler;

class EventLoop 
{
public:
    void StartLoop()
    {
        while (true)
        {
            handler_.Dipatch(poller_.Poll());
            if (!running_)
                break;
        }
    }

public:
    atomic<bool> running_;
    EventHandler handler_;
    Poller poller_;
};

class EventHandler
{
public:
    int Dispatch(const std::vector<Event *> &events)
    {
        for (auto e : events)
        {
            if (e->revent & EPOLL_IN)
            {
                e->ReadCallback();
            }
            
            if (e->revent & EPOLL_OUT)
            {
                e->WriteCallback();
            }

            if (e->revent & EPOLL_ERROR)
            {
                e->ErrorCallback();
            }

            // ...
        }
    }
    
};


class ThreadPool
{
void Enqueue()
{
    unique_lock lock(mutex_);

    while (queue_.size() == max_size_)
    {
        cond1_.wait(lock);
    }

    // 入队操作

    cond2_.notify_one();
}


void Outqueue()
{
    std::unique_lock lock(mutex_);

    while (queue_.empty())
    {A
        cond2_.wait(lock);
    }

    // 出队

    cond1_.notify_one();
}
private:
    vector<Task *> queue_;
    std::mutex mutex_;

    std::condition_variable cond1_;
    std::condition_variable cond2_;
};

{
    int; 0 3
    char;4 -
    int; 8: 11
    short 12 - 13
}
