#include <iostream>
using namespace std;

int main() {
    {
        // error
        // int i = -1, &r = 0; 
    }

    {
        int i2; 
        int *const p2 = &i2; // ok
    }
    {
        const int i = -1, &r = 0;
    }
}

