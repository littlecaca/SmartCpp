#include <algorithm>
#include <memory>
#include <utility>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::uninitialized_copy;
using std::allocator;
using std::initializer_list;
using std::for_each;
using std::pair;

/*
 * Note
 * The library containers, string, and shared_ptr classes support move as
 * well as copy. The IO and unique_ptr classes can be moved but not copied.
 * 
 * 
 * Rvalue References
 * 
 * We can bind an rvalue reference to expressions that require a conversion,
 * to literals, or to expressions that return a rvalue, but we cannot directly bind an
 * rvalue reference to an lvalue.
 * 
 * 
 * Lvalues Persist; Rvalues Are Ephemeral
 * 
 * Note
 * Rvalue references refer to objects that are about to be destroyed. Hence, 
 * we can "steal" state from an obejct bound to an rvalue reference.
 * 
 * 
 * The library move function
 * 
 * It is essential to realize that the call to move promises that
 * we do not intend to use that lvalue again except to assign to it or
 * to destroy it. After a call to move, we cannot make any assumptions 
 * about the value of the moved_from obejct.
 * 
 * 
 * Warning
 * Code that uses move should use std::move, not move. Doing so avoids
 * potential name collisions.
 * 
 * 
 * 
 * Move Constructor and Move Assignment
 * 
 * Like the copy constructor, the move constructor has an initial parameter
 * that is a reference to the class type. As in the copy constructor, any
 * additional parameters must all have default arguments.
 * 
 * 
 * 
 * Move Operations, Library Containers, and Exceptions
 * 
 * Unless the library knows that our move constructor won't throw, it will
 * do extra work to cater to the possiblity that moving an object of our
 * class type might throw.
 * 
 * Note
 * Move constructors and move assignment operators that cannot throw
 * exceptions should be marked as noexcept.
 * 
 * The library containers provide guarantees as to what they do if an
 * exception happens. As one example, vector guarantees that if an
 * exception happens when we call push_back, the vector itself will be
 * left unchanged.
 * 
 * To avoid the potential problem, vector must use a copy constructor
 * instead of a move constructor during reallocation unless it knows
 * that the element type's move constructor cannot throw an exception.
 * 
 * 
 * 
 * Move-Assignment Operator
 * 
 * Like a copy-assignment operator, a move-assignment operator
 * must guard against self-assignment.
 * 
 * A Moved-from Object Must Be Destructible
 * 
 * Warning
 * After a move operation, the "moved-from" object must remain
 * a valid, destructible object but users may make no assumptions
 * about its value.
 * 
 * 
 * 
 * The Synthesized Move Operations
 * 
 * The compiler will synthesize a move constructor or a move-assignment
 * oeprator only if the class doesn't define any of its own copy-control
 * members and if every nonstatic data member of the class can be moved
 * constructed and move assigned, respectively.
 * 
 * Unlike the copy operations, a move operation is never implicitly defined
 * as a deleted function. However, if we explicitly ask the compiler
 * to generate a move operation by using = default, and the compiler
 * is unable to move all the members, then the move operation will be
 * defined as deleted. (p667 for details)
 * 
 * 
 * Note
 * Classes that define a move constructor or move-assignment operator
 * must also define their own copy opertions. Otherwise, those members
 * are deleted by default.
 * 
 * 
 * 
 * Rvalues Are Moved, Lvalues Are Copied...
 * 
 * 
 */


class StrVec {
    pair<string *, string *> alloc_n_copy(const string *b, const string *e);
    pair<string *, string *> alloc_n(size_t);
    void free();
    void chk_n_alloc();
    void reallocate();
    void reallocate(size_t);

    allocator<string> alloc;
    // The three pointers marks the space
    string *elements;
    string *first_free;
    string *cap;
  public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const initializer_list<string> &);
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    ~StrVec() { free(); }
    // Move constructor
    StrVec(StrVec &&s) noexcept;
    // Move-Assignment Operator
    StrVec &operator=(StrVec &&rhs) noexcept;
    
    void push_back(const string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string *begin() const { return elements; }
    string *end() const { return first_free; }
    void reserve(size_t);
    void resize(size_t);
};

StrVec &StrVec::operator=(StrVec &&rhs) noexcept {
    // Direct test for self-assignment
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.elements;
        cap = rhs.cap;
        // Leave rhs in a destructible state
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

StrVec::StrVec(StrVec &&s) noexcept 
    : elements(s.elements), first_free(s.first_free), cap(s.cap) {
    // Leave s in a state in which it is safe to run the destructor
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec::StrVec(const initializer_list<string> &il) {
    auto ps = alloc_n_copy(il.begin(), il.end());
    elements = ps.first;
    first_free = cap = ps.second;
}

inline
void StrVec::push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

pair<string *, string *> StrVec::alloc_n(size_t n) {
    auto data = alloc.allocate(n);
    return {data, data + n};
}

void StrVec::free() {
    if (elements) {
        std::for_each(elements, first_free, [this](const string *sp) { alloc.destroy(sp); });
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &sv) {
    auto ps = alloc_n_copy(sv.elements, sv.first_free);
    elements = ps.first;
    first_free = cap = ps.second;
}

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto ps =  alloc_n_copy(rhs.elements, rhs.first_free);
    free();
    elements = ps.first;
    first_free = cap = ps.second;
    return *this;
}

inline
void StrVec::reallocate() {
    reallocate(size() ? size() * 2 : 1);
}

void StrVec::reallocate(size_t new_cap) {
    // Allocate space for twice as many as elements as the current size
    auto newcapacity = new_cap;
    // Allocate new memory
    auto newdata = alloc.allocate(newcapacity);
    // Move the data
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

inline
void StrVec::chk_n_alloc() {
    if (first_free == cap)
        reallocate();
}

inline
void StrVec::reserve(size_t new_cap) {
    // If there are already elements
    if (elements)
        reallocate(new_cap);
    else {
        // Or if not
        auto ps = alloc_n(new_cap);
        elements = first_free = ps.first;
        cap = ps.second;
    }
}

void StrVec::resize(size_t new_size) {
    auto num = new_size - size();
    if (num > 0) {
        for (size_t i = 0; i < num; ++i) {
            push_back(std::string());
        }
    } else
        first_free += num;
}

int main(int argc, char const *argv[])
{
    StrVec sv{"new", "old", "mountain"};
    for (auto &s : sv)
        std::cout << s << std::endl;
    
     std::cout << sv.size() << " " << sv.capacity() << std::endl;
    return 0;
}

int main(int argc, char const *argv[])
{
    // lvalue reference
    const string &s1 = "asd";

    string &&s = "sad";
    return 0;
}
