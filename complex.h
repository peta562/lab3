#ifndef COMPLEX_H
#define COMPLEX_H


#include <iostream>
#include <math.h>

using namespace std;
class Complex
{
    private:
    double real;
    double imaginary;

    public:
    //Complex();
    Complex(double rl = 0, double im = 0);  
    ~Complex();    
    Complex(const Complex &complex);
    Complex plus(const Complex &complex1, const Complex &complex2);
    Complex& operator= (const Complex &complex);

    friend Complex operator+ (const Complex &complex1, const Complex &complex2);
    friend Complex operator- (const Complex &complex1, const Complex &complex2);
    friend Complex operator* (const Complex &complex1, const Complex &complex2);
    friend Complex operator/ (const Complex &complex1, const Complex &complex2);

    void set(double rl, double im);   
    double getRealPart();    
    double getImaginaryPart();
    Complex conj();

    double absComplex(const Complex &complex);
    void showAlg();
    void showTrig();
    void showExp();
};

inline Complex operator+ (const Complex &complex1, const Complex &complex2)
{
    return(Complex(complex1.real + complex2.real, complex1.imaginary + complex2.imaginary));
}

inline Complex operator- (const Complex &complex1, const Complex &complex2)
{
    return(Complex(complex1.real - complex2.real, complex1.imaginary - complex2.imaginary));
}

inline Complex operator* (const Complex &complex1, const Complex &complex2)
{
    return(Complex(complex1.real * complex2.real - complex1.imaginary * complex2.imaginary, complex1.real * complex2.imaginary + complex1.imaginary * complex2.real));
}

inline Complex operator/ (const Complex &complex1, const Complex &complex2)
{
    double a = complex2.real * complex2.real + complex2.imaginary * complex2.imaginary;
    return(Complex((complex1.real * complex2.real + complex1.imaginary * complex2.imaginary) / a, (complex2.real * complex1.imaginary - complex1.real * complex2.imaginary) / a));
}




#endif // COMPLEX_H
