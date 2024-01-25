#include <initializer_list>
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
using std::initializer_list;

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
    template <class... Args>
    void emplace_back(Args&& ...args);
    
    void push_back(const string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string *begin() const { return elements; }
    string *end() const { return first_free; }
    void reserve(size_t);
    void resize(size_t);
};