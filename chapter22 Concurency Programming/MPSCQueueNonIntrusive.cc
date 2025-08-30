#include <atomic>

template<typename T>
class MPSCQueueNonIntrusive
{
public:
  MPSCQueueNonIntrusive()
      : _head(new Node()), _tail(_head.load(std::memory_order_relaxed)) {}

  ~MPSCQueueNonIntrusive() {
    T *output;
    while (Dequeue(output))
      delete output;

    Node *front = _head.load(std::memory_order_relaxed);
    delete front;
    }

// wait-free
    void Enqueue(T* input)
    {
        Node* node = new Node(input);
        Node* prevHead = _head.exchange(node, std::memory_order_acq_rel);
        prevHead->Next.store(node, std::memory_order_release);
    }

    bool Dequeue(T*& result)
    {
        Node* tail = _tail.load(std::memory_order_relaxed);
        Node* next = tail->Next.load(std::memory_order_acquire);
        if (!next)
            return false;

        result = next->Data;
        _tail.store(next, std::memory_order_release);
        delete tail;
        return true;
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

    MPSCQueueNonIntrusive(MPSCQueueNonIntrusive const&) = delete;
    MPSCQueueNonIntrusive& operator=(MPSCQueueNonIntrusive const&) = delete;
};

int main() {


}