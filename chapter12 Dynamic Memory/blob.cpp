#include "Blob.h"
#include <string>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

int main(int argc, char const *argv[])
{
    StrBlob b1{"you", "and", "me"};
    string s1 = b1.front();
    s1.append(" and me");
    cout << s1 << endl;
    s1.pop_back();

    const auto vec_sp = make_shared<vector<int>>(vector<int>());
    vec_sp->pop_back();
    
    return 0;
}
