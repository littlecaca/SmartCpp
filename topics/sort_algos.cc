#include <vector>
#include <iostream>    

using namespace std;

void sort(vector<int>& A) {
  for (int i = 0; i < A.size(); ++i) {
    int mn = A[i];
    int mn_idx = i;
    for (int j = i + 1; j < A.size(); ++j) {
      if (A[j] < mn) {
          mn_idx = j;
          mn = A[j];
      }
    }
    swap(A[i], A[mn_idx]);
  }
}

int main() {
    vector<int> A{1, -23, 6, 2, 88, 3};
    sort(A);
    for (auto i : A) {
        cout << i << ", ";
    }
    cout << endl;
    
    return 0;
}