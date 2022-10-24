#include <iostream>
using namespace std;

class Box 
{
    protected:
        double width;
};


class SmallBox:Box 
{
    public:     
        void setSmallWidth(double width);
        double getSmallWidth();
};


double SmallBox::getSmallWidth()
{
    return width;     
}

void SmallBox::setSmallWidth(double width)
{
    width = width;
}

int main() 
{
    SmallBox box;

    box.setSmallWidth(5.0);
    cout << "width of box " << box.getSmallWidth() << endl;

    return 0;
}