#include <string>

using std::string;

int main(int argc, char const *argv[])
{
	int i; double d; const string *ps; char *pc; void *pv;

	pv = const_cast<string*>(ps);
	pv = &d;
	i = *pc;
	pc = static_cast<char*>(pv);	
	return 0;
}