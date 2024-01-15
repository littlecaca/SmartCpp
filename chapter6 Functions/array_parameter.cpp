#include <iostream>

using std::cout;
using std::cin;
using std::endl;

/*
 * There are three techniques used to manage pointer parameters.
 * 
 * Using a Marker to Specify the Extent of an Array.
 * 
 *  Adding a end marker to the array, like C-style character strings.
 * 
 * 
 * Using the Standard Library Conventions.
 * 
 *  Passing pointers to the first and one past the last element in the array. This
 * approach is inspired by techniques used in the standard library.
 * 
 * 
 * Explicitly Passing a Size Parameter.
 */


// just as we can define a variable that is a reference to an array.
// we can define a parameter that is a reference to an array.

// incomplete array that cannot use `for-range`
void print(int (&arr)[]) {
    cout << arr[4] << " ";
    // for (auto elem : arr)
    //     cout << elem << " ";
    cout << endl;
}

void printTen(int (&arr)[10]) {
    for (auto elem : arr) {
        cout << elem << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int nums[19] = {2, 4};
    // const int &nums3[] = {1, 2};  // error: array of references is not allowed 
    int (&rn)[19] = nums;
    
    for (auto elem : rn) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}
