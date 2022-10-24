#include <iostream>

using namespace std;


int test(int a) {
    return a - 1;
}

// 函数指针可以做为参数传递给函数, 通常意义上这也叫回调函数
int test2(int (*fun)(int), int b){
    int c = fun(10) + b; 
    return c;
}

int main() {
    typedef int (*fp)(int ); 
    fp f = test;
    cout << test2(f, 1) << endl;
    return 0;
}

