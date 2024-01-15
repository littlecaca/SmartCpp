#include <vector>
#include <string>

using std::vector;
using std::string;

/*
 * The Role of the Default Constructor
 *
 * The default construcor is used automatically whenever an object is default or value
 * initialized.
 * 
 * When we explicitly request value initialization by writing an expressions of the form
 * T(), the value initialization happens.
 * 
 * In pratice, it is almost always right to provide a default constructor if other
 * constructors are being defined.
 */

int main(int argc, char const *argv[])
{
    // value initialization -> default constructor will be used
    vector<int> vi(3);
    // string s1(); // oops! declares a function, not an object

    return 0;
}
