#include <iostream>
using namespace std;

int main() {
  int a = 10, *p = &a;
  cout << *p << endl;
  a = 11;
  cout << *p << endl;
}