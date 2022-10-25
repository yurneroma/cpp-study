#include <iostream>
using namespace std;

class A 
{
    public:
        A(int i) {
            a = i;
            cout << "this is a parameterized constructor " << endl;
        }
        // default must be with a speicial funtion
        // default constructor(with no params), copy construtor, destructor is special functions
        A() = default;

        int a;
};

class B {
public:
 
    // Error, func is not a special member function.
    //int func() = default;
     
    // Error, constructor B(int, int) is not
    // a special member function.
    //B(int, int) = default;
 
    // Error, constructor B(int=0)
    // has a default argument.
    //B(int = 0) = default;
};
 


int main()
{
    A a;
    A x(1);
    return 0;
}