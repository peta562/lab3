#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(generate1()));
    connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(generate2()));

}

void MainWindow::generate1()
{
    bool notError=true;
    double real = ui->lineEditReal->text().toDouble(&notError);
    if(!notError)
    {//если нет ошибки преобразования строки в число
        ui->plainTextEdit->setPlainText(QString("Invalid value!"));
        return;
    }
    double imaginary = ui->lineEditImaginary->text().toDouble(&notError);
    if(!notError)
    {
        ui->plainTextEdit->setPlainText(QString("Invalid value!"));
        return;
    }
   arrOfObj[0].set(real, imaginary);
   arrOfObj[0].showAlg(ui->plainTextEdit);
 }

void MainWindow::generate2()
{
    bool notError=true;
    double real = ui->lineEditReal2->text().toDouble(&notError);
    if(!notError)
    {//если нет ошибки преобразования строки в число
        ui->plainTextEdit->setPlainText(QString("Invalid value!"));
        return;
    }
    double imaginary = ui->lineEditImaginary2->text().toDouble(&notError);
    if(!notError)
    {
        ui->plainTextEdit->setPlainText(QString("Invalid value!"));
        return;
    }
    arrOfObj[1].set(real, imaginary);
    arrOfObj[1].showAlg(ui->plainTextEdit);
 }

void MainWindow::plus()
{
    arrOfObj[2] = arrOfObj[0] + arrOfObj[1];
    arrOfObj[2].showAlg(ui->plainTextEdit);
    return;
}

void MainWindow::minus()
{
    arrOfObj[2] = arrOfObj[0] - arrOfObj[1];
    arrOfObj[2].showAlg(ui->plainTextEdit);
    return;
}
void MainWindow::multiply()
{
    arrOfObj[2] = arrOfObj[0] * arrOfObj[1];
    arrOfObj[2].showAlg(ui->plainTextEdit);
    return;
}

void MainWindow::division()
{
    arrOfObj[2] = arrOfObj[0] / arrOfObj[1];
    arrOfObj[2].showAlg(ui->plainTextEdit);
    return;
}

MainWindow::~MainWindow()
{
    delete ui;
}
