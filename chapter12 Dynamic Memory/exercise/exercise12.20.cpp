#include <iostream>
#include "../Blob.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[])
{
    StrBlob blob;
    StrBlobPtr blobptr(blob);
    ifstream input("input.txt");
    string line, word;
    
    // Reads from an input file
    while (getline(input, line)) {
        istringstream is(line);
        while (is >> word) {
            blob.push_back(word);
        }
        // Print to std::out
        while (true) {
            try {
                cout << blobptr.deref() << " ";
            } catch (const out_of_range& msg) {
                break;
            } catch (const runtime_error& msg) {
                cerr << msg.what() << endl;
                break;
            }
            blobptr.incr();
        }
        cout << endl;
    }

    StrBlobPtr ptr(const_cast<const StrBlob&>(blob));
    while (true) {
        try {
            cout << ptr.deref() << endl;
        } catch (const out_of_range& msg) {
            break;
        } catch (const runtime_error& msg) {
            cout << msg.what() << endl;
        }
        ptr.incr();
    }
    return 0;
}
