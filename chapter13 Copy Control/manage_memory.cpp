#include <algorithm>
#include "StrVec.h"

using namespace std;
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
 * 
 * The Function Named move Which Is Defined in utility Header
 * 
 * Calling move returns a result that causes construct to use the string
 * move constructor. We don't know what value the strings in the old StrVec
 * memory have.
 * 
 */


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
        for_each(elements, first_free, [this](const string &sp) { alloc.destroy(&sp); });
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
