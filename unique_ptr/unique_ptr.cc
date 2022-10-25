#include <iostream>
#include <memory>
using namespace std;

// unique_ptr can be returned
unique_ptr<int> clone(int p) {
  unique_ptr<int> pInt(new int(p));
  return pInt;
}

int main() {
  // 一个对象即一个内存资源
  // unique_ptr 标识对象只能由一个所有者所有.
  unique_ptr<int> pInt(new int(5));
  cout << *pInt << endl;

  // can not copy
  // unique_ptr<int> pInt2(pInt);

  // 转让所有权, 可以通过move 转让
  unique_ptr<int> pInt2 = std::move(pInt);
  cout << *pInt2 << endl;
  unique_ptr<int> pInt3(std::move(pInt2));
  cout << *pInt3 << endl;

  int p = 10;
  unique_ptr<int> ret = clone(p);
  cout << *ret << endl;

  // 创建指向int的空指针
  std::unique_ptr<int> fptr1;
  std::unique_ptr<int> fptr2(new int(4));
  auto fptr3 = std::make_unique<int>(10);

  // fptr2
  cout << "fptr2 release before: " << fptr2.get() << endl;
  int *pf = fptr2.release();
  cout << "fptr2 release after: " << fptr2.get() << " and pf value: " << *pf
       << endl;
}
