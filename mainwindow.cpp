#include "mainwindow.h"
#include "ui_mainwindow.h"

double fristnum;
bool usIsTypSecondNum =false ;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //pushButton from 0.....9 ;
    connect(ui->pushButton_0,SIGNAL(released()),this,SLOT(dijit_pressed()));//0
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(dijit_pressed()));//1
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(dijit_pressed()));//2
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(dijit_pressed()));//3
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(dijit_pressed()));//4
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(dijit_pressed()));//5
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(dijit_pressed()));//6
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(dijit_pressed()));//7
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(dijit_pressed()));//8
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(dijit_pressed()));//9
    //pushButton unary operaton ;
    connect(ui->pushButton_PlusMinus,SIGNAL(released()),this,SLOT(unary_operation_pressed()));//+/-
    connect(ui->pushButton_persent,SIGNAL(released()),this,SLOT(unary_operation_pressed()));//%
    //pushButton binary operatin ;
    connect(ui->pushButton_add,SIGNAL(released()),this,SLOT(binary_operation_pressed()));//+
    connect(ui->pushButton_subtract,SIGNAL(released()),this,SLOT(binary_operation_pressed()));//-
    connect(ui->pushButton_multiply,SIGNAL(released()),this,SLOT(binary_operation_pressed()));//*
    connect(ui->pushButton_divide,SIGNAL(released()),this,SLOT(binary_operation_pressed()));///
    //Cecked pushButon binary operation ;
    ui->pushButton_add->setCheckable(true);
    ui->pushButton_subtract->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_divide->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::dijit_pressed()
{
  QPushButton * button =(QPushButton*)sender();
  double labelnumber;
  QString newlabel;

  if((ui->pushButton_add->isChecked()||ui->pushButton_subtract->isChecked()||
          ui->pushButton_multiply->isChecked()||ui->pushButton_divide->isChecked()) && (!usIsTypSecondNum))
  {
     labelnumber=button->text().toDouble();
     usIsTypSecondNum = true ;
     newlabel=QString::number(labelnumber,'g',15);
  }
  else
  {
      if(ui->label->text().contains('.') && button->text() == "0")
      {


           newlabel = ui->label->text() + button->text() ;
      }
      else
      {
          labelnumber=(ui->label->text()+button->text()).toDouble();
          newlabel=QString::number(labelnumber,'g',15);
      }
  }
   ui->label->setText(newlabel);
}


void MainWindow::unary_operation_pressed()
{
    QPushButton * button =(QPushButton*)sender();
    double labelnumber;
    QString newlabel;
    if(button->text()=="+/-")
    {
         labelnumber=ui->label->text().toDouble();
         labelnumber*=-1;
         newlabel=QString::number(labelnumber,'g',15);
         ui->label->setText(newlabel);
    }
    if(button->text()=="%")
    {
         labelnumber=ui->label->text().toDouble();
         labelnumber*=0.01;
         newlabel=QString::number(labelnumber,'g',15);
         ui->label->setText(newlabel);
    }
}

void MainWindow::on_pushButton_Clear_released()
{
    ui->pushButton_add->setChecked(false);
    ui->pushButton_subtract->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_divide->setChecked(false);

    usIsTypSecondNum = true ;

    ui->label->setText("0");
}

void MainWindow::on_pushButton_equals_released()
{
    double labelnumber,secondnum;
    QString newlabel;

    secondnum = ui->label->text().toDouble();
    if(ui->pushButton_add->isChecked())
    {

        labelnumber=fristnum + secondnum ;
        newlabel = QString::number(labelnumber,'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_add->setChecked(false);
    }
    else if(ui->pushButton_subtract->isChecked())
    {
        labelnumber=(fristnum - secondnum);
        newlabel = QString::number(labelnumber,'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_subtract->setChecked(false);
    }
    else if(ui->pushButton_multiply->isChecked())
    {
        labelnumber=(fristnum * secondnum) ;
        newlabel = QString::number(labelnumber,'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_multiply->setChecked(false);
    }
    else if(ui->pushButton_divide->isChecked())
    {
        labelnumber=(fristnum / secondnum) ;
        newlabel = QString::number(labelnumber,'g',15);
        ui->label->setText(newlabel);
        ui->pushButton_divide->setChecked(false);
    }

    usIsTypSecondNum = false ;
}

void MainWindow::binary_operation_pressed()
{
    QPushButton * button =(QPushButton*)sender();
    fristnum=ui->label->text().toDouble();
    button->setChecked(true);
}

void MainWindow::on_pushButton_decimal_released()
{
     ui->label->setText(ui->label->text()+'.');
}
