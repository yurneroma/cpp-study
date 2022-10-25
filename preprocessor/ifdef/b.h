#include <iostream>
#define ADMIN
using namespace std;
class B 
{
    public:
        int b;
        B();
};

B::B()
{
    #ifdef ADMIN    
    this->b = 200;
    #else 
    this->b = 25;
    #endif
}