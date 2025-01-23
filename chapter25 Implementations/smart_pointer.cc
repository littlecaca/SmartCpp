#include <string>
#include <iostream>
#include <atomic>
#include <stdexcept>

template <typename T>
class SmartPointer
{
public:
    SmartPointer(T *ptr) : ptr_(ptr), reference_count_(new std::atomic<size_t>(1))
    {
    }

    SmartPointer() : SmartPointer(nullptr) {}

    SmartPointer(const SmartPointer &rhs) : ptr_(rhs.ptr_), 
        reference_count_(rhs.reference_count_)
    {
        reference_count_->fetch_add(1, std::memory_order_acq_rel);
    }

    SmartPointer &operator=(const SmartPointer &rhs)
    {
        if (this == &rhs) return *this;

        releaseCount();

        ptr_ = rhs.ptr_;
        reference_count_ = rhs.reference_count_;
        reference_count_->fetch_add(1, std::memory_order_acq_rel);
        return *this;
    }
    
    T *operator->()
    {
        if (ptr_)
            return ptr_;
        throw std::runtime_error("-> nullptr");
    }

    T &operator*()
    {
        if (ptr_)
            return *ptr_;
        throw std::runtime_error("* nullptr");
    }

    ~SmartPointer()
    {   
        releaseCount();
    }

private:
    void releaseCount()
    {
        if (ptr_ && reference_count_->fetch_sub(1, std::memory_order_acq_rel) == 1)
        {
            delete ptr_;
            delete reference_count_;
            ptr_ = nullptr;
        }
    }

private:
    T *ptr_;
    std::atomic<size_t> *reference_count_;
};

int main(int argc, char const *argv[])
{
    SmartPointer<int> si(new int(55));
    SmartPointer<std::string> ss(new std::string(12, 'c'));

    {
        auto si2 = si;
        auto ss2 = ss;
        std::cout << ss2->c_str() << std::endl;
    }

    std::cout << *si << std::endl;

    return 0;
}
