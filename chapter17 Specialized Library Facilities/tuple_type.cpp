#include <memory>
#include <string>
#include <tuple>
#include <iostream>
#include <memory>

/*
 * A "quick and dirty" data structure
 * 
 * tuple<T1, T2, ..., Tn> t;    value-initialized
 * tuple<T1, T2, ..., Tn> t(v1, v2, ..., vn);
 * make_tuple(v1, v2, ..., vn);
 * t1 == t2
 * t1 != t2
 * t1 relop t2
 * tuple_size<tupleType>::value
 * tuple_element<i, tupleType>::type
 * 
 * get<i>(t) if t is a lvalue, return a lvalue, otherwise return a rvalue reference.
 * 
 * 
 * Note
 * A tuple can be thought of as a “quick and dirty” data structure.
 * We can compare two tuples only if they have the same number of members.
 * 
 */




int main(int argc, char const *argv[])
{
    using mytype = std::tuple<std::string, size_t, double>;
    mytype data {"You", 21, 0.99872};
    std::cout << std::get<0>(data) << std::endl;
    std::cout << std::tuple_size<mytype>::value << std::endl;
    std::tuple_element<1, mytype>::type cnt = std::get<1>(data);

    return 0;
}
