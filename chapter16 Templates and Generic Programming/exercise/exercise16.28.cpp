#include <functional>
#include <iostream>
#include "MyUnique.h"
#include <string>
#include "MyShared.h"

using namespace std;

void myDelete(string *ps)
{
    cout << *ps << " has been deleted" << endl;
    delete ps;
}

int main()
{
    MyUnique<string> us(new string("sad"));
    us->append("sadadada");
    cout << *us << endl;
    
    auto ps = us.get();
    if (us)
    {
        cout << us->c_str() << endl;
    }

    MyUnique<string, decltype(myDelete) *> us2(new string("this"), &myDelete);


    shared_ptr<string> constrast;
    MyShared<string> sp(new string("sad"), [](string *p) { std::cout << "delete" << std::endl; delete p; });

    MyShared<string> sp2 = sp;
    cout << sp2.use_count() << endl;
    
    unique_ptr<string> con2, con3;

    MyUnique<string, std::function<void(string *)>> 
        up(new string("asd"), [](string *p) { cout << "uu" << endl; delete p; });

    up.reset();
    return 0;
}