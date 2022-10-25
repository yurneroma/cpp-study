#include<iostream>
using namespace std;
  
class A
{
   public:
     A() = default; 
     static int i;
};
int A::i = 1;  

int main()
{
  A obj1;
  A obj2;
  cout << obj1.i << obj2.i << endl;
  obj1.i = 2;
  obj2.i = 3;
    

  // prints value of i
  cout << obj1.i<<" "<<obj2.i;   
}