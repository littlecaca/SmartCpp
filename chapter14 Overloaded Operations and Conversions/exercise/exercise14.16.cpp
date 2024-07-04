#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

/*
 * Defining StrBlob as a collection
 *
 *
 */

#ifndef BLOB_H
#define BLOB_H

//      +-----------------------+
//      |       StrBlob         |
//      +-----------------------+

class StrBlob {
    friend class StrBlobPtr;
    friend bool operator==(const StrBlob &lhs, const StrBlob &rhs);
    friend bool operator<(const StrBlob &lhs, const StrBlob &rhs);

  public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string>);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add and remove elements
    void push_back(const std::string &t) & { data->push_back(t); }
    void push_back(const std::string &t) && { data->push_back(t); }
    void pop_back();
    // element access
    const std::string &front() const;
    const std::string &back() const;
    std::string &front();
    std::string &back();
    std::string &get(size_type index) const;
    // subscript operator
    std::string &operator[](size_t i) {
        return (*data)[i];
    }
    const std::string &operator[](size_t i) const {
        return (*data)[i];
    } 

  private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

// StrBlob Constructors
StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
StrBlob::StrBlob(std::initializer_list<std::string> i1)
    : data(std::make_shared<std::vector<std::string>>(i1)) {}

// Element Access Members
void StrBlob::check(StrBlob::size_type i, const std::string &msg) const {
    if (i >= data->size())
        throw std::out_of_range(msg);
}

const std::string &StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

const std::string &StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

std::string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

std::string &StrBlob::back() {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::string &StrBlob::get(StrBlob::size_type index) const {
    check(index, "index out of range");
    return data->at(index);
}

// Equality Operator
bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
    return lhs.data == rhs.data;
}

// Inequality Operator
bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs == rhs);
}

// Less than Operator
inline bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
    return lhs.data < rhs.data;
}

inline bool operator>(const StrBlob &lhs, const StrBlob &rhs) {
    return !(lhs < rhs);
}

//      +-------------------------+
//      |       StrBlobPtr        |
//      +-------------------------+

class StrBlobPtr {
    friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend StrBlobPtr operator+(const StrBlobPtr &lhs, int rhs);
    friend StrBlobPtr operator-(const StrBlobPtr &lhs, int rhs);
  public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(const StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz){};
    std::string &deref() const;
    StrBlobPtr &incr();

    // Increment and Decrement
    StrBlobPtr &operator++();
    StrBlobPtr &operator--();
    const StrBlobPtr operator++(int);
    const StrBlobPtr operator--(int);

    // Dereference and Arrow operators
    std::string &operator*();
    std::string *operator->();

  private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                    const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    mutable std::size_t curr;
};

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size() || i < 0)
        throw std::out_of_range(msg);
    return ret;
}

std::string &StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

// Equality Operator
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.wptr.lock() == rhs.wptr.lock() &&
           lhs.curr == rhs.curr;
}

// Inequality Operator
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return !(lhs == rhs);
}

// Increment and Decrement
StrBlobPtr &StrBlobPtr::operator++() {
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}
StrBlobPtr &StrBlobPtr::operator--() {
    check(curr - 1, "decrement past begin of StrBlobPtr");
    --curr;
    return *this;
}

const StrBlobPtr StrBlobPtr::operator++(int) {
    auto temp(*this);
    ++(*this);
    return temp;
}

const StrBlobPtr StrBlobPtr::operator--(int) {
    auto temp(*this);
    --(*this);
    return temp;
}

// Addition and Subtraction
StrBlobPtr operator+(const StrBlobPtr &lhs, int rhs) {
    auto temp = lhs;
    temp.curr += rhs;
    return temp;
}

StrBlobPtr operator-(const StrBlobPtr &lhs, int rhs) {
    auto temp = lhs;
    temp.curr -= rhs;
    return temp;
}

// Dereference and Arrow Operators
std::string &StrBlobPtr::operator*() {
    auto p = check(curr, "out of range");
    return (*p)[curr];
}

std::string *StrBlobPtr::operator->() {
    return &operator*();
}

#endif

int main(int argc, char const *argv[])
{
    StrBlobPtr p1, p2;
    p1++;
    return 0;
}
