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



