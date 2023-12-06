#include <iostream>
#include "Blob.h"

using namespace std;

StrBlobPtr test()
{
    StrBlob blob;
    blob.push_back("test");
    return StrBlobPtr(blob);
}

int main(int argc, char const *argv[])
{
    StrBlob blob;
    blob.push_back("this");
    blob.push_back("is");
    blob.push_back("a");
    blob.push_back("good");
    blob.push_back("thing!");
    StrBlobPtr bp(blob);
    cout << bp.deref() << endl;
    bp.incr();
    cout << bp.deref() << endl;

    StrBlobPtr s2 = test();
    try
    {
        cout << s2.deref() << endl;
    }
    catch (std::runtime_error &err)
    {
        cout << err.what() << endl;
    }


    return 0;
}
