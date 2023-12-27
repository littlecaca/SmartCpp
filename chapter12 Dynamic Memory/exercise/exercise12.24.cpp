#include <string>
#include <iostream>
#include <new>

using namespace std;

int main(int argc, char const *argv[])
{
    string input;
    
    while (getline(cin, input)) {
        cout << "length: " << input.length() << endl;
        char *alloc_a = new char[input.length() + 1];
        int i = 0;
        for (auto c : input) 
            alloc_a[i++] = c;
        alloc_a[i] = '\0';

        // Print the allocated char array
        cout << alloc_a << endl;
        cout << input << endl;
        delete [] alloc_a;
    }  
    return 0;
}
