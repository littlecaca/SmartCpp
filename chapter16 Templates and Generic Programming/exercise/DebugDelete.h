#include <iostream>

#pragma once

class DebugDelete
{
public:
    DebugDelete(std::ostream &s) : os(s) {}
    template <typename T>
    void operator()(T *p) const
    {
        os << "deleting unique_ptr" << std::endl; delete p;
    }

private:
    std::ostream &os;
};