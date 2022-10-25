#include <iostream>
using namespace std;

int (*pFun)(int);
int glFun(int a) {return 1;}

int main()
{
    pFun = glFun;
    (*pFun)(2);
}