#include <iostream>
using namespace std;


class complex
{
    double re, im;
public:
    complex(double r, double i): re{r}, im{i} {}
    complex(double r): re{r}, im{0} {}
    complex():re{0}, im{0} {}

    // 
    double real() const {return re;}
    void real(double d) {re = d;}

    double imag() const {return im;}
    void imag(double d) {im = d;}

};


int main()
{
    complex z = {1, 0};
    const complex cz {1,3};
    cz = z;
    z = cz;
    double x = z.real();
}