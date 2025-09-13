#include <atomic>

template<typename T>
class MPMCQueueNonIntrusive
{
public:
    MPMCQueueNonIntrusive()
        : _head(new Node()), _tail(_head.load(std::memory_order_relaxed)) {}

    ~MPMCQueueNonIntrusive() {
        T *output;
        while (Dequeue(output))
            ;

        Node *front = _head.load(std::memory_order_relaxed);
        delete front;
    }

    // wait-free
    void Enqueue(T* input)
    {
        // 尾插法
        // 通过原子交换，拿到旧的head（该旧head变为独占资源），然后将旧head的next设置为新head
        Node* node = new Node(input);
        Node* prevHead = _head.exchange(node, std::memory_order_acq_rel);
        prevHead->Next.store(node, std::memory_order_release);
    }

    // 多消费者无锁出队
    bool Dequeue(T*& result)
    {
        while (true) {
            Node* tail = _tail.load(std::memory_order_acquire);
            Node* next = tail->Next.load(std::memory_order_acquire);
            if (!next) {
                return false;
            }
            result = next->Data;
            if (!_tail.compare_exchange_weak(tail, next, std::memory_order_acq_rel)) {
                continue;   
            }
            delete tail;
            break;
        }
    }

private:
    struct Node
    {
        Node() = default;
        explicit Node(T *data) : Data(data) {}

        T* Data{nullptr};
        std::atomic<Node*> Next{nullptr};
    };

    std::atomic<Node*> _head;
    std::atomic<Node*> _tail;

    MPMCQueueNonIntrusive(MPMCQueueNonIntrusive const&) = delete;
    MPMCQueueNonIntrusive& operator=(MPMCQueueNonIntrusive const&) = delete;
};

int main() {


}