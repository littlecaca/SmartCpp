#include <string>
#include <new>
#include <algorithm>
#include <iostream>
#include <memory>

using std::string;
using std::allocator;
using std::cout;
using std::cin;
using std::endl;
using std::pair;
using std::uninitialized_copy;
using std::for_each;

/*
 * Classes That Manage Dynamic Memory
 *
 * In this section, we will implement a vector-like class,
 * which can dynamically allocate the space for the elements.
 * 
 * 
 * 
 * Moving, Not Copying, Elements during Reallocation
 * 
 * We can avoid copy the value-like string's data to reduce the overhead.
 * 
 * 
 * Move Constructors and std::move
 * 
 * We can advoid copying the strings by using two facilities introduced
 * by the new library. The library guarantees that the "moved-from" string
 * remains in a valid, destructible state.
 */


class StrVec {
    pair<string *, string *> alloc_n_copy(string *b, string *e);
    void free();
    bool chk_n_alloc();
    bool reallocate();

    allocator<string> alloc;
    // The three pointers marks the space
    string *elements;
    string *first_free;
    string *cap;
  public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    ~StrVec() { free(); }
    
    void push_back(const string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string *begin() const { return elements; }
    string *end() const { return first_free; }
};

void StrVec::push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string *, string *> StrVec::alloc_n_copy(string *b, string *e) {
    auto data = alloc.allocate(b - e);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for (auto p = first_free; p >= elements; --p)
            alloc.destroy(p);
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



int main(int argc, char const *argv[])
{
    
    allocator<string> alloc;
    
    return 0;
}
