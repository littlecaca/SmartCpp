/*
 * Concepts
 *
 * 1) unary operators, binary operators, ternary operators
 * 2) operators conversions: just like C
 * 3) Overloaded Operators: we can also define what most operators mean
 *    when applied to class types. However, the number of operands and the
 *    precedence and the associativity of the operator cannot be changed.
 * 4) lvalues and rvalues: just like C
 *    the rvalues can not be the initializer of reference type
 * 
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
#define MOD(x, y) std::cout << #x " % " #y ":\t" << (x) % (y) << std::endl

int f() {
    std::srand((unsigned)std::time(0));
    return (int)std::rand() * 4;
}

int g() {
    std::srand((unsigned)std::time(0));
    return (int)std::rand() * 6;   
}

int h() {
    std::srand((unsigned)std::time(0));
    return (int)std::rand() * 8;
}

int j() {
    std::srand((unsigned)std::time(0));
    return (int)std::rand() * 10;
}

int main(int argc, char const *argv[])
{
    std::clock_t time_start = clock();

    // order of evaluation
    // there are no guarantees as to the order in which these functions are called
    // so don't use the operand again in the same expression
    int n =  f() + g() / h() + j();
    std::cout << n << std::endl;

    // when applied to a pointer or arithmetic value, unary plus returns
    // a (possibly promoted) copy of the value of its operand
    int *pn = &n, *pn2 = +pn;   // seem useless!

    std::cout << *pn << " " << *pn2 << std::endl;
 
    // about the modulus operator
    // if m % n is nonzero, it has the same sign as m
    // earlier versions of the language permitted m % n to have the same sign as n,
    // in which case negative m / n was rounded away from zero, so the rem can be positive.
    // now, m % (-n) is equal to m % n, and (-m) % n is equal to -(m % n)
    // in this new rule, (m / n) * n + m % n always equals m

    MOD(-2, 3);
    MOD(2, -3);
    MOD(3, -2);
    MOD(2, 3);
    MOD(-2, -3);
    std::cout << std::div(-2, 3).rem << std::endl;
    std::clock_t time_end = clock() - time_start;
    std::cout << time_end / (double)CLOCKS_PER_SEC << std::endl;

    return 0;
}