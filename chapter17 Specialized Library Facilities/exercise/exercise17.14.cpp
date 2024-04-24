#include <regex>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    try
    {
        // regex r("[]\\c254");
        // regex r("[254");
        // regex r("*?254");
    } catch (regex_error e)
    {
        cout << e.what() << "\n" << e.code() << endl;
    }
    
    return 0;
}
