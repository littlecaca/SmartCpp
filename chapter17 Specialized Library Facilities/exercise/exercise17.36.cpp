#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << left;
    cout << setw(20) << "default format: " << setw(10) <<  100 * sqrt(2.0) << '\n' 
         << setw(20) << "scientific: " << scientific << 100 * sqrt(2.0) << '\n'
         << setw(20) << "fixed decimal: " << fixed << 100 * sqrt(2.0) << '\n'
         << setw(20) << "hexadecimal: " << hexfloat << uppercase << 100 * sqrt(2.0) << nouppercase << '\n'
         << setw(20) << "use defaults: " << defaultfloat << 100 * sqrt(2.0) << "\n\n";
    return 0;
}
