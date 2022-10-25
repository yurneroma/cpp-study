#include <iostream>

using namespace std;

// 类型参数, 可变类型参数
template <class T, class U, class V>
class Foo{};

template<typename... Arguments>
class vtclass{};
vtclass< > vtinstance1;
vtclass<int> vtinstance2;
vtclass<float, bool> vtinstance3;

int main(){

}