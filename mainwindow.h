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
    void showTrig1();
    void showTrig2();
    void showExp1();
    void showExp2();
    void conj1();
    void conj2();
    void comp();

private:
    Ui::MainWindow *ui;
    Complex arrOfObj[5]; // массив объектов(по заданию) по умолчанию веществ. и действ. часть равны 0
};

#endif // MAINWINDOW_H
