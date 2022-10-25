#include <iostream>
#include <memory>

using namespace std;

void foo(shared_ptr<int> i) { (*i)++; }

int main() {
  auto pointer = make_shared<int>(10);
  foo(pointer);
  cout << *pointer << endl;

  auto pointer2 = pointer;
  auto pointer3 = pointer;

  // get the raw pointer
  int *p = pointer.get();

  cout << "pointer.use_count() = " << pointer.use_count() << endl;
  cout << "pointer2.use_count() = " << pointer2.use_count() << endl;
  cout << "pointer3.use_count() = " << pointer3.use_count() << endl;

  pointer.reset();
  cout << "pointer.use_count() = " << pointer.use_count() << endl;
  cout << "pointer2.use_count() = " << pointer2.use_count() << endl;
  cout << "pointer3.use_count() = " << pointer3.use_count() << endl;

  pointer2.reset();
  cout << "pointer.use_count() = " << pointer.use_count() << endl;
  cout << "pointer2.use_count() = " << pointer2.use_count() << endl;
  cout << "pointer3.use_count() = " << pointer3.use_count() << endl;

  pointer3.reset();
  cout << "pointer.use_count() = " << pointer.use_count() << endl;
  cout << "pointer2.use_count() = " << pointer2.use_count() << endl;
  cout << "pointer3.use_count() = " << pointer3.use_count() << endl;

  return 0;
}