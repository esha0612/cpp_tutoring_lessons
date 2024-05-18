// Create a class Complex with data members as real and imaginary part. Support overloaded operators +,- and * for this class.

#include <iostream>

using namespace std;

class Complex
{
    int real;
    int imaginary;

public:
    Complex(int real, int imaginary) : real(real), imaginary(imaginary) {}

    Complex operator+(Complex &complex)
    {
        return Complex(real + complex.real, imaginary + complex.imaginary);
    }

    Complex operator-(Complex &complex)
    {
        return Complex(real - complex.real, imaginary - complex.imaginary);
    }

    Complex operator*(Complex &complex)
    {
        return Complex(real * complex.real - imaginary * complex.imaginary, real * complex.imaginary + imaginary * complex.real);
    }

    // Let's try overloading unary operators as well.
    Complex operator-()
    {
        return Complex(-real, -imaginary);
    }

    Complex operator++()
    {
        return Complex(real + 1, imaginary);
    }

    Complex operator++(int)
    {
        return Complex(real, imaginary + 1);
    }

    Complex operator--()
    {
        return Complex(real - 1, imaginary);
    }

    Complex operator--(int)
    {
        return Complex(real, imaginary - 1);
    }

    void display()
    {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

int main()
{
    Complex c1(2, 3);
    Complex c2(4, 5);

    Complex c3 = c1 + c2;
    c3.display();

    Complex c4 = c1 - c2;
    c4.display();

    Complex c5 = c1 * c2;
    c5.display();

    Complex c6 = -c1;
    c6.display();

    Complex c7 = ++c1;
    c7.display();

    Complex c8 = c1++;
    c8.display();

    Complex c9 = --c1;
    c9.display();

    return 0;
}