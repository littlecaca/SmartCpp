#include <string>

class Employee {
  public:
    constexpr static int x = 9;
    
  private:
    static u_int64_t generator;
};

u_int64_t Employee::generator = 0;

void test(const u_int64_t &) {}

int main(int argc, char const *argv[])
{
    /* code */
    int h = Employee::x;
    test(Employee::x);
    return 0;
}
