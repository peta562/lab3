#include <iostream>
#include "complex.h"

using namespace std;

/*Complex::Complex()
{
    real = 0;
    imaginary = 0;
}*/

Complex::Complex(double rl, double im)
{
    real = rl;
    imaginary = im;
}

Complex::~Complex()
{
}

Complex::Complex(const Complex &complex)
{
    real = complex.real;
    imaginary = complex.imaginary;
}

void Complex::set(double rl, double im)
{
    real = rl;
    imaginary = im;
}

double Complex::getRealPart()
{
    return real;
}

double Complex::getImaginaryPart()
{
    return imaginary;
}

void Complex::show()
{
    if(imaginary > 0)
        cout << "complex number: {" << real << " + " << imaginary << "i}";
    else if(imaginary == 0)
        cout << "complex number: " << real;
    else
        cout << "complex number: {" << real <<  imaginary << "i}";

}

Complex Complex::operator= (const Complex &complex)
{
    real = complex.real;
    imaginary = complex.imaginary;
    return *this;
}


Complex Complex::plus (const Complex &complex1, const Complex &complex2)
{
    real = complex1.real + complex2.real;
    imaginary = complex1.imaginary + complex2.imaginary;

}


