#include <iostream>
#include <string>

class Employee {
  public:
    Employee() : serial(gen_serial()) {}
    Employee(const std::string &n) : name(n), serial(gen_serial()) {}
    std::string name;
    const u_int64_t serial;

    Employee(const Employee &e) : name(e.name), serial(gen_serial()) {}


  private:
    static u_int64_t generator;
    u_int64_t gen_serial() { return generator++; }
};

u_int64_t Employee::generator = 0;

void test(const u_int64_t &) {}

int main(int argc, char const *argv[]) {
    /* code */
    Employee e1, e2, e3, e4("Tom"), e5("Lily");
    std::cout << e1.serial << " " << e2.serial << " " << e3.serial
              << std::endl << e4.name << ": " << e4.serial
              << std::endl << e5.name << ": " << e5.serial
              << std::endl;
    
    Employee e6(e4);
    std::cout << e6.name << ": " << e6.serial << std::endl;
    return 0;
}
