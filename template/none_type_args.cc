#include <iostream>

using namespace std;

// 非类型参数, cpp支持非类型参数, 也成为值参数, 作为模板参数
template<typename T, size_t L>
class MyArray {
public:
    T arr[L];
    MyArray(){}
};

int main() {
    MyArray<int, 10> a;
    cout << a.arr[0] << endl;
}