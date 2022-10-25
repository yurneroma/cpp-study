template <typename T>
class Complex 
{
    public:
        Complex(T a, Tb)
        {
            this->a = a;
            this->b = b;
        }

        Complex<T> operator+(Complex &c)
        {
            Complex<T> tmp(this->a + c.a, this->b+c.b);
            return tmp;
        }
};