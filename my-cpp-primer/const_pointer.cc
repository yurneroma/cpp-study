#include <iostream>

using namespace std;

int main() {
    // const reference
    double i = 3.14;
    const double &r = i;
    cout << r << endl;

    // pointer to const
    const double *pi = &i; 

    // 允许const pointer 更换指向的对象,但不允许通过 pointer modify the origial value
    double dval = 6.1;
    pi = &dval; 
    cout << *pi << endl;
    // *pi = 10; error, cannot modify i by pi, pi is a const obj

    // const pointer 
    // 不能更换指向的对象,但可以改变对象的值
    int errNumb = 0;
    int *const curErr = &errNumb;
    cout << "before " << *curErr << endl;
    *curErr = 10;
    cout << "after " << *curErr << endl;
    





}
