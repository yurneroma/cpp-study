#include <iostream>
using namespace std;

int main() {
  const int i = 100;
  // int &r = i; error, 引用必须和源类型保持一致
  const int &r = i;

  int a = 10;
  const int &r1 = a;
  const int &r2 = 42;
  // int &r3 = 42; error, non const reference's value must be a left

  // int &r4 = r1 * 2; the same, non const reference's value must be a left
  // value

  double dval = 3.14;
  const int &ri = dval;
}