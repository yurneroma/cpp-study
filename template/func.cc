#include <iostream>
using namespace std;

// 求最小值模板函数
template <typename T> // typename 占位符, T 类型泛型 
T minimum(const T& lhs, const T& rhs) {
    return lhs < rhs ? lhs : rhs;
}


int main() {
    int a = 10;
    int b = 11;

    auto i = minimum<int>(a, b); // 由于是函数模板, 编译器可以从参数类型中推导出类型,  可以像普通函数一样调用 minimum(a,b);
    cout  <<  "minimum is: " << i << endl; 
}