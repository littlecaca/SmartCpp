#include <exception>

using namespace std;

class exceptionType { };
typedef int EXCPTYPE;

// (a)
void a()
{
    throw exceptionType();
}

// (b)
void b()
{
    throw exception();
}

// (c)
void c()
{
    throw 8888;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
