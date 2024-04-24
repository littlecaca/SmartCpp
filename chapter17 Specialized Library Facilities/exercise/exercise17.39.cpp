#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    fstream inOut("sample.txt", fstream::ate | fstream::in | fstream::out);
    if (!inOut)
        throw runtime_error("Can't open the file");
    
    auto end_marker = inOut.tellg();
    inOut.seekg(0, fstream::beg);
    string line;
    int count = 0;

    while (inOut && inOut.tellg() != end_marker && getline(inOut, line))
    {
        cout << line.size() << " : " << line << endl;
        auto marker = inOut.tellg();
        inOut.seekp(0, fstream::end);
        inOut << count << " -------- " << count + line.size() << "\n";
        count += line.size() + 1;
        inOut.seekg(marker);
    }
    
    return 0;
}
