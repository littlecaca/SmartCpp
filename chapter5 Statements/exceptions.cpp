#include <iostream>
#include <exception>
#include <stdexcept>
#include <new>
#include <typeinfo>

using std::exception;   // communicates only that an exception occurred but provides no additional information
using std::bad_alloc;
using std::bad_cast;

// the standard exception classes defined in <stdexcept>

using std::runtime_error;   // problem that can be detected only at run time
using std::range_error;     // run-time error: result generated outside the range of meaningful values
using std::overflow_error;  // run-time error: computation that overflowed
using std::underflow_error; // run-time error: computation that underflowed
using std::logic_error;     // error in the logic of the program
using std::domain_error;    // logic-error: argument for which no result exists
using std::invalid_argument;// logic-error: inappropriate argument
using std::length_error;    // logic-error: attempt to create an object larger than the maximum sizd for that type
using std::out_of_range;    // logic-error: used a value outside the valid range

int main(int argc, char const *argv[])
{
    /*
     * We can create, copy, and assign objects of any of the exception types. 
     * We can only default initialze `exception`, `bad_alloc`, and `bad_cast` objects.
     * The other exceptions have the opposite hehavior: we can initialze those objects
     * from either a string or a C-style string.
     */
    return 0;
}
