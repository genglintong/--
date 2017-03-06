#include "users.h"
#include "ui_users.h"
#include "login.h"
#include "searcha.h"
#include "watch.h"
#include "QDebug"

Users::Users(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Users)
{
    ui->setupUi(this);
}

Users::~Users()
{
    delete ui;
}
string name;

void Users::on_pushButton_clicked()//关闭
{
    QSound *button=new QSound(":/b.wav");//声音
    button->play();
    close();
    login *l=new login(this);//重新打开登陆界面
    l->show();
}

void Users::MIMA(QString a,QString b)//显示用户名
{
    ui->label_2->setText(a);
    string s=a.toStdString();
    name =s;
}

void Users::on_queding_clicked()//用户两个功能
{
    QSound *button=new QSound(":/b.wav");//声音
    button->play();
    if(ui->luxian->isChecked())//查找
    {
        searcha *sea=new searcha(this);
        sea->show();
        id1=startTimer(1000);//开始计时器
        t1=0;//重置计时器

    }
    else if(ui->zhuangtai->isChecked())//观察
    {
        watch *w=new watch(this);
        w->show();
    }
}
void Users::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==id1)
    {
        t1++;//计算输入路线时间
        //qDebug()<<t1<<t;
        update();
    }
}
