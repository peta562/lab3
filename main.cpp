#include "mainwindow.h"
#include "complex.h"
#include <QApplication>

using namespace std;
#define N 5
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    Complex arrOfObj[N] = {
        Complex(2,4),
        Complex(3,4.5),
        Complex(5,12),
        Complex(6.12,4),
        Complex(2.5,6.3)
    };
    arrOfObj[3].plus(arrOfObj[1], arrOfObj[0]);
    arrOfObj[3].show();
    arrOfObj[1].set(3,456);
    for(int i = 0;i < N; i++){
        cout << arrOfObj[i].getRealPart();
        cout << "  ";
        cout << arrOfObj[i].getImaginaryPart();
        cout << "\n";
    }
    arrOfObj[1].show();
    return a.exec();
}
