#include <iostream>
using namespace std;

template <class T, class U = char> class A {
    public:
        T x;
        U y;
        A() { cout << "Constructor Called" << endl; }
};


int main()
{
    A<char, char> a;
    A<int, double> b; 
    A<char> c;

    return 0;
}