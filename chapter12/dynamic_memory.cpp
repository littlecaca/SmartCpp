#include <iostream>
#include <memory>
#include <new>
#include <stdexcept>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::make_shared;
using std::shared_ptr;
using std::string;
using std::unique_ptr;
using std::vector;
using std::weak_ptr;
// both bad_alloc and nothrow is defined in the new header
using std::bad_alloc;
using std::nothrow;

/*
 * Smart Pointers
 *
 * Smart pointers ensure that the objects to which they point
 * are automatically freed when it is appropriate to da so.
 *
 * Programs use the heap for objects at run time. Out code must
 * explicitly destroy such objects when they are no longer needed.
 *
 *
 *
 * Dynamic Memory and Smart Pointers
 *
 * shared_ptr (allows multiple pointers to refer the same obejct)
 *
 * unique_ptr ("owns" the object to which it points)
 *
 * weak_ptr (does not protect the refered objects from the collection of
 * garbge)
 *
 * All three are defined in the memory header.
 *
 * A default initialized smart pointer holds a null pointer.
 *
 *
 *
 * Operations common to shared_ptr and unique_ptr
 *
 * shared_ptr<T> sp
 * unique_ptr<T> up
 * p
 * *p
 * p->mem
 * p.get()              Returns the pointer in p. The object to which the
 *                      returned pointer points will disappear when the smart
 * pointer deletes it. 
 * 
 * swap(p, q) p.swap(q)
 *
 *
 * Operations Specfic to shared_ptr
 *
 * make_shared<T> (args)    Returns a shared_ptr pointing to a dynamically
 *                          allocated object of type T. Uses args to initialize
 * that obejct. share_ptr<T>
 *
 * p(q)                     p is a copy of the shared_ptr q; increments the
 * count in q. The pointer in q must be convertible to T*. p = q Decrements p's
 * reference count and increments q's count; deletes p's existing memory if p's
 * count goes to 0.
 *
 * p.unique()               Returns true if p.use_count() is one; false
 * otherwise.
 *
 * p.use_count()            Returns the number of
 *                          objects sharing with p; may be a slow operation,
 * intended primarily for debugging purposes.
 *
 *
 *
 * Copying and Assigning shared_ptr
 *
 * When we copy or assign a shared_ptr, each shared_ptr keeps track of how many
 * other shared_ptrs point to the same object.
 *
 * We can think of a shared_ptr as if it has an associated count, usually
 * referred to as a reference count. When we pass it to or return it from
 * function by value, the counter also increments.
 *
 * It is up to the implementation whether to use a counter or another data
 * structure to keep track of how many shared_ptrs point to the same state.
 *
 *
 * shared_ptrs Automatically Destroy Their Objects...
 *
 * It does so through another special mamber function known as a destructor.
 * Analogous to its constructors, each class has a destructor.
 *
 * One way that shared_ptrs might stay around after you need them is if you put
 * shared_ptrs in a container and subsequently reorder the container so that you
 * don't need all the elements. You should be sure to erase shared_ptr elements
 * once you no longer need those elements.
 *
 *
 * Classes with Resources That Have Dynamic Lifetime
 *
 * Programs tend to use dynamic memory for one fo three purposes:
 *      1. They don't know how many objects they'll need
 *      2. They don't know the precise type of the objects they need
 *      3. They want to share data between several objects.
 *
 *
 *
 * Managing Memory Directly
 *
 * Best Practices
 *
 * For the same reasons as we usually initialize variables, it is also a good
 * idea to initialize dynamically allocated objects.
 *
 * Dynamically Allocated const Objects
 *
 * Like any other const, a dynamically allocated const object must ne
 * initialized.
 *
 * Memory Exhaustion
 *
 * By default, if new is unable to allocate the requested storage, it throws
 * an exception of type bad_alloc. We can prevent new from throwing an exception
 * by using a different form of new. If this form of new is unable to allocate
 * the requested storage, it will return a null pointer.
 *
 * This form of new is referred to as placement new.
 *
 * Freeing Dynamic Memory
 *
 * The pointer we pass to delete must either point to dynamically allocated
 * memory or be a null pointer. Deleting a pinter to memory that was not
 * allocated by new, or deleting the same pinter value more than once, is
 * undefined.
 *
 * Caution: Managing Dynamic Memory Is Error-Prone
 *
 * There are three common problems with using new and delete to manage dynamic
 * memory:
 * 1. Forgetting to delete memory.
 * 2. Using an object after it has been deleted. This error can sometimes be
 * detected by making the pointer null after the delete.
 * 3. Deleting the same memory twice.
 *
 * Resetting the Value of a Pointer after a delete
 *
 * After the delete, the pointer becomes what is referred to as a dangling
 * pointer. Dangling pointers have all the problems of uninitiallized pointers.
 *
 *
 *
 * Using shared_ptrs with new
 *
 * If we do not initialize a smart pointer, it is initialized as a null pointer.
 * We can also initialize a smart pointer from a pointer returned by new.
 *
 * shared_ptr<T> p(q)       q must point to memory allocated by new and must be
 * convertible to T* 
 * 
 * shared_ptr<T> p(u)       p assumes ownership from the
 * unique_ptr u; makes u null 
 * 
 * shared_ptr<T> p(q, d)    p will use the callable
 * object d in place of delete to free q. 
 * 
 * shared_ptr<T> p(p2, d)   p is a copy
 * of the shared_ptr p2 except that p uses the callable object d in place of
 * delete.
 *
 * p.reset()                If p is the only shared_ptr pointing at its obejct,
 * frees p's existing object. Makes p null. 
 * 
 * p.reset(q)               Makes p point to q. 
 * 
 * p.reset(q, d)            Calls d to free q otherwise uses delete
 * to free q.
 *
 * The smart pointer constructors that take pointers are explicit.
 * Hence, we must use the direct form of initialization to initialze a smart
 * pointer.
 *
 *
 *
 * Don't Mix Ordinary Pointers and Smart Pointers
 *
 * Warning: It is dangerous to use a built-in pointer to access an object owned
 * by a smart pointer, because we may not know when that object is destroyed.
 *
 * Don't Use `get` to Initialize or Assign Another Smart Pointer
 *
 * The code that uses the return from get must not delete that pointer.
 * It is an error to bind another smart pointer to the pointer returned by get.
 *
 *
 *
 * Smart Pointers and Exceptions
 *
 * When we use a smart pointer, the smart pointer class ensures that memroy is
 * freed when it is no longer needed even if the block is existed prematurely.
 *
 * Smart Pointers and Dumb Classes
 *
 * Using Our Own Deletion Code
 *
 * Caution: Smart Pointer Pitfalls
 *
 * 1. Don't use the same built-in pointer value to initialize (or reset) more
 * than one smart pointer.
 * 2. Don't delete the pointer returned from get().
 * 3. Don't use get() to initialize or reset another smart pointer.
 * 4. If you use a pointer returned by get(), remember that the pointer
 * will become invalid when the last corresponding smart pointer gose away.
 * 5. If you use a smart pointer to manage a resource other than memory
 * allocated by new, remember to pass a deleter.
 *
 */

typedef int destination;
typedef int * connection;

int main(int argc, char const *argv[]) {
    // define a shared_ptr class that can point at a string
    shared_ptr<string> p1;

    // define and initialize a shared_ptr class
    shared_ptr<int> p2 = make_shared<int>(42);

    // p3 points to a string with value 9999999999
    shared_ptr<string> p3 = make_shared<string>(10, '9');

    // copy p3 to p4
    auto p4(p3);

    void test(void);
    void test2();

    test();
    test2();

    auto r = make_shared<int>(42);
    // the int pointed by r is automatically freed as part of assigning p2 to r
    r = p2;

    // Using new to Dynamically Allocate and Initialize Objects

    int *pi = new int;
    delete pi;

    string *ps = new string;
    delete ps;

    string *ps2 = new string(10, '9');
    delete ps2;

    vector<int> *pv = new vector<int>{0, 1, 2, 3, 4, 5, 6};
    delete pv;

    // indicate the value initialization
    int *pi2 = new int();
    delete pi2;

    // we can use auto to deduce one single initializer's type to allocate
    auto *pa = new auto(r);
    delete pa;

    vector<int> v1{1, 2, 3};
    const vector<int> v2(v1);
    cout << "this is : " << v2.front() << endl;

    const vector<int> v3{1, 2, 3};
    cout << "that was : " << v3.back() << endl;

    // allocate and initialize a const int
    const int *pci = new const int(1024);
    delete pci;

    // allocate a int without throw exception, if fails, get nullptr
    int *pi3 = new (nothrow) int(11);

    // initialize a smart pointer from a pointer returned by new
    shared_ptr<int> pi4(new int(42));

    pi4.reset(pi3);

    if (pi4 == nullptr) {
        cout << "pi4 is nullptr" << endl;
    }

    // A dangerous scenario mixing ordinary pointers and smart pointers
    void process(shared_ptr<int>);

    int *pi5 = new int(42);
    process(shared_ptr<int>(pi5));
    int j = *pi5; // undefined: pi5 is a dangling pointer

    // Using our own deletion code
    connection connect(destination &);
    void dis_connect(destination &);
    destination d;
    {
        connection c = connect(d);
        shared_ptr<connection> p(&c, [](connection *pc) { dis_connect(**pc); });
        // use the connection
        // when f exits even if by an exception, the connection will be
        // properly closed
    }
    
    // If reset() takes no arguments, it will make itself null.
    pi4.reset();
    if (pi4 == nullptr)
        cout << "pi4 is nullptr" << endl;
    else 
        cout << "pi4 is not!" << endl;

        
    pi4 = nullptr;
    pi4.reset(new int(43));
    cout << *pi4 << endl;
    return 0;
}

vector<int> get_vec() { return vector<int>{1, 2, 3}; }

void test() {
    vector<int> vc(get_vec());
    for (auto i : vc) {
        cout << i << endl;
    }
    vc.clear();
    const vector<int> vi{1, 2};
    const std::string ss = "123";
    cout << ss << endl;
}

class Test {
  public:
    Test() = default;
    Test(int i) { data = i; }
    int get() const { return data; }
    void set(int i) { data = i; }

  private:
    int data;
};

void test2() {
    const Test t1(2);

    cout << t1.get() << endl;
}

void test3() {
    // const auto *pa = new const Test; // error: the data memeber must be
    // initialized
}

void process(shared_ptr<int> ptr) {}



connection connect(destination &) { return new int(1); }
void dis_connect(destination &) {}
