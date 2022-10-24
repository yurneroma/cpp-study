#include <iostream>

using namespace std;


void t1() {cout << "test1" << endl;}
void t2() {cout << "test2" << endl;}
void t3() {cout << "test3" << endl;}

int main() {
    typedef void (*fp)(void);

    // 声明了函数指针数组
    fp b[] = {t1, t2, t3};
    b[0]();

    return 0;
}
