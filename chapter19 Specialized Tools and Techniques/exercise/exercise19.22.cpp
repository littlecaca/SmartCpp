#include <string>
#include <iostream>

struct Sales_data {
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.;
    short rate{0};
    short count = {0};
};


class Token2
{
public:
    Token2() : tok(INT), ival(0) {}
    Token2(const Token2 &t) : tok(t.tok), data(t.data) { copyUnion(t); }
    Token2(Token2 &&t) : tok(t.tok), data(std::move(t.data)) { moveUnion(std::move(t)); }
    Token2 &operator=(Token2 &&);
    Token2 &operator=(const Token2 &);
    ~Token2()
    {
        if (tok == STR)
            sval.~basic_string();
    }
    Token2 &operator=(const std::string &);
    Token2 &operator=(char);
    Token2 &operator=(int);
    Token2 &operator=(double);

private:
    // unscoped enumeration
    // Used as the discriminant
    enum
    {
        INT,
        CHAR,
        DBL,
        STR
    } tok;
    union
    {
        char cval;
        int ival;
        double dval;
        std::string sval;
    };

    void copyUnion(const Token2 &);
    void moveUnion(Token2 &&);
    Sales_data data;
};

void Token2::copyUnion(const Token2 &t)
{
    switch (t.tok)
    {
    case INT:
        ival = t.ival;
        break;
    case CHAR:
        cval = t.cval;
        break;
    case DBL:
        dval = t.dval;
        break;
    case STR:
        new (&sval) std::string(t.sval);
        break;
    }
}

void Token2::moveUnion(Token2 &&t)
{
    switch (t.tok)
    {
    case INT:
        ival = t.ival;
        break;
    case CHAR:
        cval = t.cval;
        break;
    case DBL:
        dval = t.dval;
        break;
    case STR:
        new (&sval) std::string(std::move(t.sval));
        break;
    }
}

Token2 &Token2::operator=(Token2 &&t)
{
    data = std::move(t.data);
    if (tok == STR && t.tok != STR)
        sval.~basic_string();
    if (tok == STR && t.tok == STR)
        sval = std::move(t.sval);
    else
        moveUnion(std::move(t));
    tok = t.tok;

    return *this;
}

Token2 &Token2::operator=(const Token2 &t)
{
    data = t.data;
    if (tok == STR && t.tok != STR)
        sval.~basic_string();
    if (tok == STR && t.tok == STR)
        sval = t.sval;
    else
        copyUnion(t);
    tok = t.tok;

    return *this;
}

Token2 &Token2::operator=(const std::string &rhs)
{
    if (tok == STR)
        sval = rhs;
    else new (&sval) std::string(rhs);
    return *this;
}

Token2 &Token2::operator=(char rhs)
{
    if (tok == STR)
        sval.~basic_string();
    cval = rhs;
    return *this;
}

Token2 &Token2::operator=(int rhs)
{
    if (tok == STR)
        sval.~basic_string();
    ival = rhs;
    return *this;
}

Token2 &Token2::operator=(double rhs)
{
    if (tok == STR)
        sval.~basic_string();
    dval = rhs;
    return *this;
}

int main(int argc, char const *argv[])
{

    Token2 t2, t3, t4;

    t2 = "you";
    t3 = 3.4;
    t4 = 1;
    t2 = t3;
    
    return 0;
}
