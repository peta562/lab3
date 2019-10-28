#include "complex.h"


using namespace std;


Complex::Complex(double rl, double im) // конструктор с параметрами и по умолчанию
{
    real = rl;
    imaginary = im;
}

Complex::~Complex() // деструктор
{
}

Complex::Complex(const Complex &complex) // конструктор копирования
{
    real = complex.real;
    imaginary = complex.imaginary;
}

void Complex::set(double rl, double im) // задать значение
{
    real = rl;
    imaginary = im;
}

double Complex::getRealPart() // получить действительную часть
{
    return real;
}

double Complex::getImaginaryPart() // получить веществ. часть
{
    return imaginary;
}

void Complex::showAlg(QPlainTextEdit* textBrowser) // вывод в алгоритмической форме
{
    if(imaginary > 0)
        textBrowser->setPlainText(QString("complex number: %1 + %2i").arg(real).arg(imaginary));
    else if(imaginary == 0)
        textBrowser->setPlainText(QString("complex number: %1").arg(real));
    else
        textBrowser->setPlainText(QString("complex number: %1  %2i").arg(real).arg(imaginary));

}

void Complex::showTrig() // вывод в тригонометрической форме
{
    double r = sqrt(real * real + imaginary * imaginary);
    if(imaginary > 0)
        cout <<  r <<  " * (cos(" << atan(imaginary/real) << ") + sin(" << atan(imaginary/real) << ")i)" << endl;
    else if (imaginary == 0)
        cout << "cannot be represented in trigonometric form" << endl;
    else
        cout <<  r <<  " * (cos(" << abs(atan(imaginary/real)) << ") - sin(" << abs(atan(imaginary/real)) << ")i)" << endl;
}

void Complex::showExp() // вывод в экспонентциальной форме
{
    double r = sqrt(real * real + imaginary * imaginary);
    cout <<  r <<  " * e^("<< atan(imaginary/real) << "i)" << endl;
}


Complex& Complex::operator= (const Complex &complex) // перегрузка оператора =
{
    real = complex.real;
    imaginary = complex.imaginary;
    return *this;
}

Complex Complex::conj() // сопряженное число
{
    imaginary = -imaginary;
    return *this;
}

bool compare(Complex &complex1, Complex &complex2, char s) // функция сравения
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

