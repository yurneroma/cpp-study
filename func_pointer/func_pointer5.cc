#include <iostream>

using namespace std;

//对于 nonstatic member function （非静态成员函数）取地址，获得该函数在内存中的实际地址
//对于 virtual function（虚函数）, 其地址在编译时期是未知的，所以对于 virtual member function（虚成员函数）取其地址，所能获得的只是一个索引值
class A {
    public:
        A(int aa = 0):a(aa){}
        ~A(){}

        void setA(int aa = 1) {
            a = aa;
        }

        virtual void print() {cout << "A: " << a << endl;}
        virtual void printa() {cout << "A1: " << a << endl;}
    private:
        int a;
};

class B: public A {
    public:
        B():A(), b(0) {}
        B(int aa, int bb):A(aa), b(bb){}
        ~B(){}

        virtual void print() {
            A::print();
            cout << "B: " << b << endl;
        }

        virtual void printa() {
            A::printa();
            cout << "B: " << b << endl;
        }
    private:
        int b;
};

int main() {
    A a;
    B b;
    void (A::*ptr)(int) = &A::setA;

    A *pa = &a;

    //对于非虚函数， 获取其在内存中的地址
    printf("A::set(): %p\n", &A::setA);
    //对于虚函数， 获取其在虚函数表的offset
    printf("A::print(): %p\n", &A::print);
    printf("A::print(): %p\n", &A::printa);


    a.print();
    a.setA(10);
    a.print();

    // 对于指向类成员函数的函数指针， 引用时， 必须传入一个类对象的this指针，所以必须由类对象调用
    (pa->*ptr)(1000);
    a.print();

    return 0;
}
