#include "tujing.h"
#include "ui_tujing.h"

tujing::tujing(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::tujing)
{
    ui->setupUi(this);
}

tujing::~tujing()
{
    delete ui;
}

 QString tujing::CITY(){
     QString s;
     s=ui->lineEdit->text();
     return s;
 }
