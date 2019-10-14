#ifndef COMPLEX_H
#define COMPLEX_H


#include <iostream>

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
    Complex operator= (Complex &complex);

    void set(double rl, double im);   
    double getRealPart();    
    double getImaginaryPart();    
    void show();   
};

#endif // COMPLEX_H
