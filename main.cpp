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

    return a.exec();
}
