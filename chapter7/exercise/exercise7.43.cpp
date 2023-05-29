#include <vector>

using std::vector;

class NoDefault {
  public:
    NoDefault(int i) : grade(i) {}
  private:
    int grade = 0;
};

class C {
  private:
    NoDefault no;
    double price;
};

int main(int argc, char const *argv[])
{
    // vector<NoDefault> vec(10);   // error: no matching function for call to ‘NoDefault::NoDefault()’
    // vector<C> vec2(10); // ‘C::C()’ is implicitly deleted because the default definition would be ill-formed:
    return 0;
}


