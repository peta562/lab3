#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "complex.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void generate1();
    void generate2();
    void plus();
    void minus();
    void multiply();
    void division();


private:
    Ui::MainWindow *ui;
    Complex arrOfObj[5] = { // иницилизируем массив объектов
        Complex(),
        Complex(),
        Complex(),
        Complex(),
        Complex()
    };


};

#endif // MAINWINDOW_H
