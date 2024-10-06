#include <iostream>
#include <limits>
#include <queue>
#include <unordered_map>


namespace N1
{
    namespace N2
    {
        class Foo
        {
        public:
            void func1();
        };

        namespace N3
        {
            // void Foo::func1()
            // {

            // }
        }
    }
}

int main(int argc, char const *argv[])
{

    int n = 1 << 31;
    int m = INT_MIN;
    std::cout << n << std::endl;
    std::cout << m << std::endl;
    std::priority_queue<int> que;
    std::queue<int> que2;
    std::unordered_map<int, int> um;
    return 0;
}
