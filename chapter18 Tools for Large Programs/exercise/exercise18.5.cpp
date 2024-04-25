#include <cstdlib>
#include <exception>
#include <iostream>

using namespace std;

void subcall(bool throw_error = false)
{
    if (throw_error)
        throw runtime_error("subcall error");
}
    
int main(int argc, char const *argv[])
{
    try
    {
        subcall(true);
    }
    catch (const length_error &e)
    {
        cout << e.what() << endl;
        abort();
    }
    catch (const out_of_range &e)
    {   
        cout << e.what() << endl;
        abort();
    }
    catch (const logic_error &e)
    {
        cout << e.what() << endl;
        abort();
    }
    catch (const runtime_error &e)
    {
        cout << e.what() << endl;
        abort();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        abort();
    }

    return 0;
}
