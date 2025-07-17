#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * 本专题目的是为了练习各种指针类型的定义方式，包括但不限于：
 * 1. 多维指针
 * 2. 指向数组的指针
 * 3. 指向函数的指针
 * 4. 指向类成员变量的指针
 * 5. 指向类成员函数的指针
 */

int like(int x, float y, double z) {
  return x * y - z;
}

class Base {
public:
  int age_;
  float height_;
};

int main() {
  cout << "指向数组的指针：" << endl;
  int array[1000] = {};
  iota(array, array + 1000, 1);
  using PA = int (*)[20];
  // typedef int (*PA)[20];
  PA pa = (PA)array;
  for (int i = 0; i < 5; ++i) {
    if (i != 0) {
      cout << " ";
    }
    cout << pa[0][0];
    ++pa;
  }
  cout << endl;

  cout << "指向函数的指针：" << endl;
  // 函数的指针与函数本身可以隐式转换
  typedef int (*Func)(int, float, double);
  Func func = like;   // implicit conversion to pointer
  cout << func(2, 2, 3) << endl;

  cout << "指向类成员变量的指针" << endl;

  return 0;
}