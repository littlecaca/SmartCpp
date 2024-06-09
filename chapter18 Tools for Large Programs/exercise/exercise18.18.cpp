#include <string>
#include <iostream>

/**
 * 
*/
template <typename T>
void swap(T v1, T v2)
{
    using std::swap; 
    std::cout << "local swap" << std::endl;
    swap(v1.mem1, v2.mem1);
    // swap remaining members of type T
}

struct Node
{
    /* data */
    int mem1;
};

struct Node2
{
    /* data */
    int mem1;
};

// void swap(const std::string, const std::string)
// {}

int main(int argc, char const *argv[])
{
    Node n1, n2;
    Node2 n3, n4;
    swap(n1, n2);
    swap(n3, n4);
    
    std::swap(n1, n2);
    std::swap(n3, n4);

    using namespace std;
    std::string s1, s2;
    swap(s1, s2);
    std::swap(s1, s2);
    return 0;
}
