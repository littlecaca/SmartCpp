#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    cout << "default format: " << 100 * sqrt(2.0) << '\n' << "scientific: " << scientific << 100 * sqrt(2.0) <<
'\n'
 << "fixed decimal: " << fixed << 100 * sqrt(2.0) <<
'\n'
 << "hexadecimal: " << hexfloat << uppercase << 100 * sqrt(2.0) << nouppercase <<
'\n'
 << "use defaults: " << defaultfloat << 100 * sqrt(2.0) << "\n\n";
    return 0;
}
