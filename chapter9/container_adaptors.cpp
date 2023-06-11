#include <iostream>
#include <stack>
#include <deque>
#include <string>
#include <vector>
#include <queue>

using std::vector;
using std::string;
using std::deque;
using std::cout;
using std::endl;
using std::flush;
using std::stack;
using std::ends;
using std::queue;
using std::priority_queue;

/*
 * An adaptor is a general concept in the library. There are container, iterator, and function adaptors.
 * Essentially, an adaptor is a mechanism for making one thing ack like another. For example, the stack adaptor
 * takes a sequential container (other than array or forward_list) and makes it operate as if it were a stack.
 * 
 * Operations and Types Common to the Container Adaptors
 * 
 * size_type
 * value_type
 * container_type
 * A a;             Create a new empty adaptor named a
 * A a(c);          Create a new adaptor named `a` with a copy of the container c
 * relational operators
 * a.empty()
 * a.size()
 * swap(a, b)
 * a.swap(b)
 * 
 * 
 * Defining an Adaptor
 * 
 * Each adaptor defines two constructors: the default constructor that creates an empty
 * obejct, and a constructor that takes a container and initializes the adaptor by copying
 * the given container.
 * 
 * By default both stack and queue are implemented in terms of deque, and a priority_queue is
 * implemented on a vector. We can override the default container type by naming a sequential
 * container as a second type argument when we create the adaptor.
 * 
 * A stack requires only push_back, pop_back, and back operations,so we can use any of the 
 * remaining container type for stack (other than arrays and forward_lists). The queue adaptor
 * requires back, push_back, front, and pop_front, so it can be built on a list or deque but
 * not on a vector. A priority_queue requires random access in addition to the front, push_back,
 * and pop_back operations, so it can be built on a vector or a deque but not on a list. 
 * 
 * 
 * Stack Adaptor
 * 
 * s.pop()          
 * s.push(item)
 * s.emplace(args)
 * s.top()
 * 
 * 
 * Queue Adaptors
 * 
 * q.pop()      Removes the front element or highest-priority element
 *              from queue or priority_queue, respectively.
 * q.front()
 * q.back()     valid only for queue
 * q.top()      valid only for priority_queue
 * q.push(item)
 * q.emplace(args)
 * 
 */

int main(int argc, char const *argv[])
{
    deque<int> d1{1, 2, 3, 4};

    stack<int> stk(d1);

    stack<string, vector<string>> str_stk;

    // queue can not use vector
    // queue<string, vector<string>> str_que;
    queue<string, deque<string>> str_que;
    str_que.push("you");
    str_que.push("are");
    str_que.pop();
    cout << str_que.front() << endl;
    return 0;
}
