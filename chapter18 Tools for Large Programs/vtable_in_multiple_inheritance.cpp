#include <iostream>
#include <stdio.h>

using namespace std;

class B1 {
public:
    virtual void barB1() {cout << "B1::bar" << endl;}
    virtual void fooB1() {cout << "B1::foo" << endl;}
};

class B2 {
public:
    virtual void barB2() {cout << "B2::bar" << endl;}
    virtual void fooB2() {cout << "B2::foo" << endl;}
    virtual void nailB2() {cout << "B2::nail" << endl;}
};

class D : public B1, B2 {
public:
    void fooB1() {cout << "D::foo" << endl;}
    void nailB2() {cout << "D::nail" << endl;}
    virtual void fooD1() {cout << "D::fooD1" << endl;}
    void barB2() {cout << "D::bar" << endl;}
};

typedef void (*Func)();

int main() {
    D tt;
    Func* vptr1 = *(Func**)&tt;
    Func* vptr2 = *((Func**)&tt + 1);

    vptr1[0]();
    vptr1[1]();
    vptr1[2]();
    vptr1[3]();
    vptr1[4]();
    cout<<"\\\\\\\\\\\\"<<endl;
    vptr2[0]();
    vptr2[1]();
    cout << (unsigned long long)vptr1 << " " << (unsigned long long)vptr2 << endl;
    return 0;
}