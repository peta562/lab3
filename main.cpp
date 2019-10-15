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

    Complex arrOfObj[N] = { // иницилизируем массив объектов
        Complex(2,-4),
        Complex(3,4.5),
        Complex(5,12),
        Complex(6.12,4),
        Complex(2.5,6.3)
    };

    cout << compare(arrOfObj[1], arrOfObj[2], '=') << endl;

    arrOfObj[3] = arrOfObj[1] + arrOfObj[0];
    arrOfObj[3].showAlg();
    //arrOfObj[1].set(3,456);

    arrOfObj[2] = arrOfObj[0] - arrOfObj[1];
    arrOfObj[2].showAlg();

    arrOfObj[4] = arrOfObj[0] / arrOfObj[1];
    arrOfObj[4].showAlg();

    arrOfObj[0].showTrig();
    arrOfObj[0].showExp();

    /*for(int i = 0;i < N; i++){
        cout << arrOfObj[i].getRealPart();
        cout << "  ";
        cout << arrOfObj[i].getImaginaryPart();
        cout << "\n";
    }*/
    arrOfObj[1].conj();
    arrOfObj[1].showAlg();
    return a.exec();
}
