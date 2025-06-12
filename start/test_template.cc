#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> vi;
  auto &i = vi.emplace_back();
  cout << i << endl;
  return 0;
}
