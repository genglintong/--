#include "luxian.h"
#include "ui_luxian.h"

luxian::luxian(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::luxian)
{
    ui->setupUi(this);
}

luxian::~luxian()
{
    delete ui;
}

void luxian::Print(QString s){//将路线输出之界面
    ui->lineEdit->setText(s);
}
