#include <iostream>
using namespace std;


int main()
{
    int a = 10;
    char c = 'a';

    int* q = (int*)(&c);
    int* p = static_cast<int*>(&c);
    return 0;
}