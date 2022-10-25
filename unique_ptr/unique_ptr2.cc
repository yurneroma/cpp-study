#include <iostream>
#include <memory>

using namespace std;

struct Foo {
  Foo() { cout << "Foo::Foo" << endl; }
  ~Foo() { cout << "Foo::~Foo" << endl; }
  void foo() { cout << "Foo::foo" << endl; }
};

void f(const Foo &) { cout << "f(const Foo&)" << endl; }

int main() {
  unique_ptr<Foo> p1(make_unique<Foo>());
  if (p1) p1->foo();
  {
    unique_ptr<Foo> p2(move(p1));
    f(p2);
  }
}