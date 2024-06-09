namespace primerLib {
    void compute(); 
    void compute(const void *);
}

using primerLib::compute;
void compute(int);
void compute(double, double = 3.4);
void compute(char*, char* = 0);

/**
 * All are candidates, and 4 are viable.
*/
void f()
{
    compute(0);
}