#include <iostream>

using namespace std;

//
int test(int a) {
    return a;
}

// typedef 可以简化函数指针的定义
int main() {
    typedef int (*fp)(int a); 
    fp f = test;
    cout << f(2) << endl;
    return 0;
}

