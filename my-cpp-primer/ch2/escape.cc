#include <iostream>

using namespace std;

// 转义序列, 不可打印字符
int main() {
  cout << '\n';
  cout << '\a' << '\n';
  cout << '\115' << '\n';
  cout << '\x4d' << '\n';
}