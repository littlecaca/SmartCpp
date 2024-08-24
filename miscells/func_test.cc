#include <functional>

typedef std::function<void(int)> Callback;


int main(int argc, char const *argv[])
{
    Callback cb = Callback();
    // cb(12);
    return 0;
}
