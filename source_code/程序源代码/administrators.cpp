#include "administrators.h"
#include "ui_administrators.h"
#include "login.h"
#include "watch.h"
#include<QFile>
#include "add.h"
#include <QSound>

administrators::administrators(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrators)
{
    ui->setupUi(this);
}

administrators::~administrators()
{
    delete ui;
}

void administrators::on_pushButton_clicked()//结束该界面
{
    QSound *button=new QSound(":/b.wav");//开始音乐
    button->play();
    //QString zhanghu;
    close();
    login *l=new login(this);//重新打开登陆界面
    //ui->name->setText(zhanghu);
    l->show();
}
void administrators::MIMA(QString a,QString b)//将登陆界面用户名显示在当前界面
{
    ui->name->setText(b);
    name="";//管理员姓名设立空标志位
}

void administrators::on_pushButton_2_clicked()//管理员三种功能
{
    QSound *button=new QSound(":/b.wav");//开始音乐
    button->play();
    if(ui->radioButton->isChecked())
    {
       Open();//显示日志文件
    }
    else if(ui->radioButton_2->isChecked())
    {
        watch *a=new watch(this);
        a->show();//观察用户状态
    }
    else if(ui->radioButton_3->isChecked()){

        add *b=new add(this);
        b->show();//添加路线
    }
}

void administrators::Open(void)//打开日志文件
{
    QFile *file=new QFile("1.txt");//打开文件
    file->open(QIODevice::ReadOnly|QIODevice::Text);
    QString data=QString(file->readAll());//都出所有数据
    ui->textBrowser->setText(data);//将数据写入界面
    file->close();//文件关闭
}
