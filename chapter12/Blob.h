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

  public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string>);
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add and remove elements
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    // element access
    const std::string &front() const;
    const std::string &back() const;
    std::string &front();
    std::string &back();

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

//      +-------------------------+
//      |       StrBlobPtr        |
//      +-------------------------+

class StrBlobPtr {
  public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz){};
    std::string &deref() const;
    StrBlobPtr &incr();

  private:
    std::shared_ptr<std::vector<std::string>> check(std::size_t,
                                                    const std::string &) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret;
}

std::string &StrBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}
#endif