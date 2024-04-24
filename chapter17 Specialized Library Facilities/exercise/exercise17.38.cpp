#include <fstream>
#include <iostream>

using namespace std;

/*
 * Use the unformatted version of getline to read a file a
 * line at a time. Test your program by giving it a file that contains empty lines
 * as well as lines that are longer than the character array that you pass to
 * getline.
 */

int main(int argc, char const *argv[])
{
    /* code */
    #define SIZE 10

    char line[SIZE];

    ifstream is("sample.txt");
    while (!is.eof())
    {
        is.getline(line, SIZE);
        cout << line;
        // the failbit will be set if getline reads line that are longer than the character array.
        if (is.fail())
        {
            if (is.gcount() == SIZE - 1)
                is.clear();
            else
                break;
        }
        else cout << endl;
    }
    
    if (is.fail())
        cout << "fail" << endl;
    else cout << "no fail" << endl;
    
    return 0;
}
