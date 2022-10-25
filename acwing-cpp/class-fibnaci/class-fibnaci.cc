#include <iostream>
using namespace std;

class Fibnacci {
    public:
        int fib(int n) {
            if (n == 0) return 0; 
            else if (n == 1) return 1;
            else if (n == 2) return 2; 
            else  return fib(n-1) + fib(n-2);
        }
};

int main() {
    Fibnacci f; 
    int n;
    cin >> n;
    cout << f.fib(n) << endl;
}