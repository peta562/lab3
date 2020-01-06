#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <math.h>
#include <QPlainTextEdit>
#include <QMainWindow>
#include <QMessageBox>
#include <QObject>


using namespace std;
class Complex
{
    private:
    double real;
    double imaginary;

    public:
    Complex(double rl = 0, double im = 0);  
    ~Complex();    
    Complex(const Complex &complex);

    Complex& operator= (const Complex &complex);

    friend Complex operator+ (const Complex &complex1, const Complex &complex2);
    friend Complex operator- (const Complex &complex1, const Complex &complex2);
    friend Complex operator* (const Complex &complex1, const Complex &complex2);
    friend Complex operator/ (const Complex &complex1, const Complex &complex2);

    void set(double rl, double im);   
    double getRealPart();    
    double getImaginaryPart();
    Complex conj();

    void showAlg(QPlainTextEdit* textBrowser);
    void showTrig(QPlainTextEdit* textBrowser);
    void showExp(QPlainTextEdit* textBrowser);
};

inline Complex operator+ (const Complex &complex1, const Complex &complex2) // перегрузка оператора +
{
    return(Complex(complex1.real + complex2.real, complex1.imaginary + complex2.imaginary));
}

inline Complex operator- (const Complex &complex1, const Complex &complex2)// перегрузка оператора -
{
    return(Complex(complex1.real - complex2.real, complex1.imaginary - complex2.imaginary));
}

inline Complex operator* (const Complex &complex1, const Complex &complex2) // перегрузка оператора *
{
    return(Complex(complex1.real * complex2.real - complex1.imaginary * complex2.imaginary, complex1.real * complex2.imaginary + complex1.imaginary * complex2.real));
}

inline Complex operator/ (const Complex &complex1, const Complex &complex2) // перегрузка оператора /
{
    try
    {
        if(complex2.real == 0 || complex2.imaginary == 0)
            throw "division by zero";
        double a = complex2.real * complex2.real + complex2.imaginary * complex2.imaginary;
        return(Complex((complex1.real * complex2.real + complex1.imaginary * complex2.imaginary) / a, (complex2.real * complex1.imaginary - complex1.real * complex2.imaginary) / a));
    }
    catch(const char *s)
    {
           QMessageBox::critical(nullptr, QObject::tr("Ошибка"),QObject::tr(s));
    }
    return 0;
}

bool compare(Complex &complex1, Complex &complex2, QString s);


#endif // COMPLEX_H
