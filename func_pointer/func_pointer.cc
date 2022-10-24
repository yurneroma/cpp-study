#include <iostream>

using namespace std;
// 函数指针是一个 指向函数的指针变量
// data_type (*func_pointer) (data_types args1, data_types args2...); 
//

int test(int a) {
    return a; 
}

int main() {
    int (*fp)(int a);
    fp = &test;
    cout << fp(2) << endl;
    return 0;
}
