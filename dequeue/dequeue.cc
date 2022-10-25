#include <iostream>
#include <deque>
using namespace std;

int main() {
    std::deque<int> d = {7, 5, 16, 9};
    d.push_front(1);
    d.push_back(99);

    for (int n : d)
        cout << n << ' '; 

    return 0;
}


