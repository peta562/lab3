#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->comboBox->addItem(QString('<'));
    ui->comboBox->addItem(QString('>'));
    ui->comboBox->addItem(QString('='));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(generate1()));
    connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(generate2()));

}

void MainWindow::generate1() // записываем первое число
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

void MainWindow::generate2() // записываем второе число
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

void MainWindow::showTrig1()
{
    arrOfObj[0].showTrig(ui->plainTextEdit);
}

void MainWindow::showTrig2()
{
    arrOfObj[1].showTrig(ui->plainTextEdit);
}

void MainWindow::showExp1()
{
    arrOfObj[0].showExp(ui->plainTextEdit);
}

void MainWindow::showExp2()
{
    arrOfObj[1].showExp(ui->plainTextEdit);
}


void MainWindow::conj1()
{
    arrOfObj[0].conj();
    arrOfObj[0].showAlg(ui->plainTextEdit);
}

void MainWindow::conj2()
{
    arrOfObj[1].conj();
    arrOfObj[1].showAlg(ui->plainTextEdit);
}



void MainWindow::plus()
{
    arrOfObj[2] = arrOfObj[0] + arrOfObj[1];
    arrOfObj[2].showAlg(ui->plainTextEdit);
}

void MainWindow::minus()
{
    arrOfObj[2] = arrOfObj[0] - arrOfObj[1];
    arrOfObj[2].showAlg(ui->plainTextEdit);
}
void MainWindow::multiply()
{
    arrOfObj[2] = arrOfObj[0] * arrOfObj[1];
    arrOfObj[2].showAlg(ui->plainTextEdit);
}

void MainWindow::division()
{
    arrOfObj[2] = arrOfObj[0] / arrOfObj[1];
    arrOfObj[2].showAlg(ui->plainTextEdit);
}


void MainWindow::comp()
{
    QString s = ui->comboBox->currentText();

    if(compare(arrOfObj[0], arrOfObj[1], s) == true)
        ui->plainTextEdit->setPlainText(QString("true"));
    else
        ui->plainTextEdit->setPlainText(QString("false"));


}
MainWindow::~MainWindow()
{
    delete ui;
}
