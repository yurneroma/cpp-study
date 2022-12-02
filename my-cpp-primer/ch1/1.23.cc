#include <iostream>

#include "Sales_item.h"

using namespace std;

int main() {
  Sales_item item, curItem;
  if (cin >> curItem) {
    int cnt = 1;
    while (cin >> item) {
      if (item.isbn() == curItem.isbn()) {
        cnt++;
      } else {
        cout << curItem.isbn() << " " << cnt << endl;
        cnt = 1;
        curItem = item;
      }
    }
    cout << curItem.isbn() << " " << cnt << endl;
  }

  return 0;
}