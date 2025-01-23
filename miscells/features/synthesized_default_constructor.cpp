class Base
{
public:
    Base &operator=(const Base &);
    
private:
    // const int a;
    // ~Base();
};

/**
 * 编译器自动生成默认构造函数的条件：
 * 1. 未显式定义构造函数
 * 2. 析构函数可以被访问
 * 3. 未定义const或者引用类型的成员变量
 * 4. 类成员变量的默认构造函数可以被访问
 * 5. 如果有父类，则父类的默认构造函数可以被访问
 */

int main(int argc, char const *argv[])
{
    Base b;
    return 0;
}
