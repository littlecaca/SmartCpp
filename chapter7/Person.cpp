#include "Person.h"
#include <iostream>

using std::cout;
using std::cin;

std::istream &read(std::istream &is, Person &np) {
    is >> np.name >> np.address;
    return is;
}

std::ostream &print(std::ostream &os, Person const &op) {
    os << "(" << op.name << ", " << op.address << ")";
    return os;
}

