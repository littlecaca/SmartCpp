
/*
 * Local Objects
 * 
 * In C++, names have `scope`, and objects have `lifetimes`. Parameters and variables defined inside a
 * function body are referred to as local variables.
 * 
 * 
 * Automatic Objects
 * 
 * Objects that exist only while a block is executing are known as automatic objects. After execution exits
 * a block, the values of the automatic objects created in that block are undefined.
 * 
 * 
 * Local Static Objects
 * 
 * 
 * 
 */
int fun() {
    int i, j, q;
    i = 520, j = 519, q = 518;
    {
        int m, n;
        m = 521, n = 522;
        i += m + n;
    }
    while (--i) {
        int h = i + q;
    }
    int a = 517, b = 516, l = 588;

    return i;
}


int main(int argc, char const *argv[])
{
    int a = fun();
    return 0;
}

