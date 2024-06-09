class Class {  };
class Base : public Class {  };
class D1 : virtual public Base {  };
class D2 : public Base {  };
class MI : public D1, public D2 {  };
class Final : public MI, public Class {  };

int main(int argc, char const *argv[])
{
    Class *pc;
    // pc = new Final;
    Base *pb;
    // pb = new Final;
    return 0;
}

