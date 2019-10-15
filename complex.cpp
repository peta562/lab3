#include <iostream>
#include "complex.h"
#include <math.h>

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

void Complex::showAlg()
{
    if(imaginary > 0)
        cout << "complex number: {" << real << " + " << imaginary << "i}" << endl;
    else if(imaginary == 0)
        cout << "complex number: " << real << endl;
    else
        cout << "complex number: {" << real <<  imaginary << "i}"<< endl;

}

void Complex::showTrig()
{
    double r = sqrt(real * real + imaginary * imaginary);
    if(imaginary > 0)
        cout <<  r <<  " * (cos(" << atan(imaginary/real) << ") + sin(" << atan(imaginary/real) << ")i)" << endl;
    else if (imaginary == 0)
        cout << "cannot be represented in trigonometric form" << endl;
    else
        cout <<  r <<  " * (cos(" << abs(atan(imaginary/real)) << ") - sin(" << abs(atan(imaginary/real)) << ")i)" << endl;
}

void Complex::showExp()
{
    double r = sqrt(real * real + imaginary * imaginary);
    cout <<  r <<  " * e^("<< atan(imaginary/real) << "i)" << endl;


}


Complex& Complex::operator= (const Complex &complex)
{
    real = complex.real;
    imaginary = complex.imaginary;
    return *this;
}

Complex Complex::conj()
{
    imaginary = -imaginary;
    return *this;
}

bool compare(Complex &complex1, Complex &complex2, char s)
{
    double rl1 = complex1.getRealPart();
    double rl2 = complex2.getRealPart();
    double im1 = complex1.getImaginaryPart();
    double im2 = complex2.getImaginaryPart();

    if(s == '>')
    {
        if(sqrt(rl1 * rl1 + im1 * im1) > sqrt(rl2 * rl2 + im2 * im2))
                return true;
        else
            return false;
    }
    else if (s == '<')
    {
        if(sqrt(rl1 * rl1 + im1 * im1) < sqrt(rl2 * rl2 + im2 * im2))
                return true;
        else
            return false;
    }
    else if (s == '=')
    {
        if(sqrt(rl1 * rl1 + im1 * im1) == sqrt(rl2 * rl2 + im2 * im2))
                return true;
        else
            return false;
    }
    else {
        cout << "Error value of s " << endl;
        return false;
    }
}

