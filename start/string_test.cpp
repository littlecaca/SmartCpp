#include <string.h>

#include <iostream>
#include <string>


using namespace std;

int main(int argc, char const *argv[]) {
  string s;
  s.resize(5);

  cout << s.size() << endl;
  s.append("213131");
  cout << s.substr(0, 6) << endl;
  cout << s << endl;
  cout << s.data() << endl;
  cout << strlen(s.data()) << endl;

  return 0;
}
