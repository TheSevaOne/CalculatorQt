#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include <QDoubleValidator>
#include <QLocale>
#include "math.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_5->setValidator(new QDoubleValidator(-10000, 10000, 0 ,ui->lineEdit_5));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_5_textEdited(const QString &arg1)
{
   // Default
   QString  input =  ui -> lineEdit_5->text();
   double digit = input.toDouble();
   ui->lineEdit->setText(QString::number(digit));
   ui->lineEdit_3->setText(QString::number(digit));
   ui->lineEdit_10->setText(QString::number(digit));

   double tofar =((digit)*5/9+32);
   tofar = round(tofar*10)/10;
   ui->lineEdit_2->setText(QString::number(tofar));

   double tokel =((digit)+273.15);
   tofar = round(tokel*10)/10;
   ui->lineEdit_6->setText(QString::number(tokel));

    double tocel=(digit-32)*5/9;
    tocel=round(tocel*10)/10;
    ui->lineEdit_4->setText(QString::number(tocel));
    double kel=(digit-32)*5/9+273.15;
    kel=round(kel*10)/10;
    ui->lineEdit_7->setText(QString::number(kel));

    double kfar=(digit-273.15)*9/5+32;
    kfar= round(kfar*10)/10;
    ui->lineEdit_9->setText(QString::number(kfar));
    double kcel=digit-273.15;
    kcel=round(kcel*10)/10;
    ui->lineEdit_8->setText(QString::number(kcel));

   if(input==""|| input=="-")
    {
    ui->lineEdit_9->setText("");
    ui->lineEdit_6->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit->setText("");
    ui->lineEdit_8->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_10->setText("");
    ui->lineEdit_7->setText("");
    ui->lineEdit_4->setText("");
}



}
