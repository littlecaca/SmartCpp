#include <iostream>

using namespace std;


class Query_base
{
public:
    virtual ~Query_base() {}
};

class AndQuery : public Query_base
{

};

class OrQuery : public Query_base
{

};

int main(int argc, char const *argv[])
{
    Query_base *qp1 = new AndQuery;
    Query_base *qp2 = new AndQuery;

    if (typeid(*qp1) == typeid(*qp2))
    {
        cout << "same type" << endl;
        if (typeid(*qp1) == typeid(AndQuery))
        {
            cout << "yes, it is" << endl;
        }
    }

    return 0;
}
