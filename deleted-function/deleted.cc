#include <iostream>
using namespace std; 


class A 
{
    public:
        A(int i):m(i){}
         
        friend std::ostream& operator<< (std::ostream& os, const A& a) 
        {
            os << a.m << endl;
            return os;
        }

        // 无法使用 a1 = a2 赋值运算
        A& operator=(const A& ) = delete;

        // copy constructor is disaled
        A(const A&)=delete;
    public:
        int m;
};

int main()
{
    A a1(3), a2(2), a3(1);
    a2 = a1; 
    a3 = A(a1);
    cout << "a2 is " << a2 <<  endl;
    return 0;
}