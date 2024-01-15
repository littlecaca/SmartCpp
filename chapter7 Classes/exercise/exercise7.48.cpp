#include <iostream>
#include <string>
#include "../access_specifiers.h"

using std::string;
using std::cout;
using std::endl;

int main(int argc, char const *argv[])
{
    string null_isbn("9-999");
    Sales_data item1(null_isbn);
    // it's ok, because this only requires one implicit concersion 
    // which is from 'const char *' to `string`
    Sales_data item2("9-999");

    print(cout, item1) << endl;
    print(cout ,item2) << endl;

    return 0;
}


