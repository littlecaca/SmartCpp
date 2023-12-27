#include <string>


template <typename T1, typename T2>
bool compare(T1, T2);

int main(int argc, char const *argv[])
{
    int i = 12;
    double j = 78;
    compare(i, j);
    compare(std::string(), i);
    
    return 0;
}
