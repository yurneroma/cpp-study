#include <iostream>
using namespace std;

void func(int arr[], int length) {
  // return the size of a pointer, not the total array size.
  // on arm64 the size if 8
  size_t num = sizeof(arr);
  cout << "arm64 pointer size is: " << num << endl;

  for (int i = 0; i < length; i++) {
    cout << arr[i] << " ";
  }
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int len = sizeof(arr) / sizeof(arr[0]);
  func(arr, len);
}