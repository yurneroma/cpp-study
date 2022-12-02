#include <iostream>
using namespace std;

int main() {
  unsigned u = 10, u2 = 42;
  cout << u2 - u << endl;
  cout << u - u2 << endl;

  int i = 10, i2 = 42;
  cout << i2 - i << endl;
  cout << i - i2 << endl;
  // signed 正整数和unsigned 表示是一致的。
  // signed 负数部分转unsigned时，最高位符号位会被认为是数字, 相当于加了一个
  // 1 << (n-1), n是位数
  cout << i - u << endl;
  cout << u - i << endl;
}