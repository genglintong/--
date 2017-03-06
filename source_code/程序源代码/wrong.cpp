#include "wrong.h"
#include "ui_wrong.h"

wrong::wrong(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::wrong)
{
    ui->setupUi(this);
}

wrong::~wrong()
{
    delete ui;
}
