#include "login.h"
#include "ui_login.h"
#include "users.h"
#include "administrators.h"
#include "zhuce.h"
#include "watch.h"
#include<QTextStream>
#include<zhanghu.h>
#include<string>
#include "wrong.h"
#include "jmlog.h"

using namespace std;

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    id1=startTimer(1000);
}

login::~login()
{
    delete ui;
}

void login::on_denglu_clicked()
{
    QSound *button=new QSound(":/b.wav");//声音显示
    button->play();
    QString zhanghu=ui->lineEdit->text();//用户输入
    QString mima=ui->lineEdit_2->text();
    string c;
    string a,b;
    a=zhanghu.toStdString();//转化为std字符串
    b=mima.toStdString();

    if(ui->yonghu->isChecked())
    {
       c="user";
        if(judge(a,b,c)){//判断是否注册
        close();
       Users *user=new Users(this);
       user->show();
       user->MIMA(zhanghu,mima);//将用户名传递到user界面
       usercome(a,t,0);//记录
        }
        else{
            wrong *w=new wrong(this);//打开错误界面
            w->show();
        }
    }
    else if(ui->guanliyuan->isChecked())
    {
        c="admin";
        if(judge(a,b,c)){//判断是否注册
        close();
        administrators *admin=new administrators(this);
        admin->show();
        admin->MIMA(zhanghu,mima);//将管理员名称传递到其界面
        usercome(a,t,1);//记录
        }
        else{
            wrong *w=new wrong(this);
            w->show();//错误界面
        }
    }
}

void login::on_close_clicked()//关闭界面
{
    QSound *button=new QSound(":/b.wav");//声音显示
    button->play();
    close();//关闭界面
}

void login::on_zhuce_clicked()//注册函数
{
    QSound *button=new QSound(":/b.wav");//声音显示
    button->play();
    QString zhanghu=ui->lineEdit->text();//接受字符串
    QString mima=ui->lineEdit_2->text();
    string a,b;
    a=zhanghu.toStdString();
    b=mima.toStdString();//转换

    if(ui->yonghu->isChecked())
    {
        write(a,b,"user");//写入密码文件
    }
    else if(ui->guanliyuan->isChecked())
    {
        write(a,b,"admin");
    }
    zhuce *z=new zhuce(this);
    z->show();//弹出注册成功窗口
}

void login::timerEvent(QTimerEvent *event)//时间事件
{
    if(event->timerId()==id1)
    {
        t++;//时间推进
        //printf("(%d)\n",t);//调试信息
    }
}
