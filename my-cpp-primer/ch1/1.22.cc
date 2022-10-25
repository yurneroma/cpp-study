#include <iostream>

#include "Sales_item.h"

using namespace std;

int main() {
  Sales_item item;
  Sales_item total;
  if (cin >> total) {
    while (cin >> item) {
      total += item;
    }
    cout << total << endl;
  }
}