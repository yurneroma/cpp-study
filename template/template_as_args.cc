#include <iostream>
using namespace std;


// 模板可以作为模板参数
template<typename T, template<typename, int> class Arr>
class MyClass2 {
    T t;
    Arr<T, 10>;
};

int main() {

}