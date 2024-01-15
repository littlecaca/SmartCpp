#include <vector>
#include <iostream>

using std::vector;

vector<double> vd(10);

class Example {
  public:
    static constexpr double rate = 6;
    static const int vecSize = 21;
    static vector<double> vec;
};

vector<double> Example::vec(Example::vecSize);

int main(int argc, char const *argv[])
{
    Example::vec.push_back(3.2);
    Example::vec.push_back(3.2);
    Example::vec.push_back(3.2);

    vector<double> vec(Example::vecSize);
    std::cout << vec.size() << std::endl;
    std::cout << Example::vec.size() << std::endl;
    std::cout << vd.size() << std::endl;
    return 0;
}
