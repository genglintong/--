#include "chenggong.h"
#include "ui_chenggong.h"

chenggong::chenggong(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chenggong)
{
    ui->setupUi(this);
}

chenggong::~chenggong()
{
    delete ui;
}
