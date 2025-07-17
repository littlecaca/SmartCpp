
// case1: 函数模版参数类型推导，函数是否可以推导为指针的引用？
template <class T> void f1(T *&arg1) {}

void f1_c();
void f1_t() {
  // f1(f1_c);
}

// 结果：不可以
// 分析：如果模版参数是引用类型，相当于lower-level的函数到函数指针的转换，这个是不被允许的。
// 函数模版参数类型推断时允许的类型转换：
// 1. top-level const
// 2. low-level const
// 3. fuction or array to pointer to fuction or the element

// case2: 模版参数类型推导时，如果多个参数对统一类型推导出的结果不一样会怎么样？
template <class T> void f2(T *arg1, T *arg2) {}
template <class T> void f2_c(T *arg1) {}

void f2_t() {
  const int *a;
  int *b;
  // f2(a, b);
}

// 结果：会报错
// 分析：arg1对应的T被推导为const int，而 arg2对应的T被推导为int，
// 虽然T如果被推导为const int，能够满足类型转换的条件，但是由于每个参数
// 是独立参与推导的，推导出来的模版参数类型必须完全相同，所以会报错。