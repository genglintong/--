#include "searcha.h"
#include "ui_searcha.h"
#include "luxian.h"
#include "plan.h"
#include "global.h"
#include <QString>
#include "init.h"
#include "tujing.h"
#include <QDebug>
#include "graph.h"
#include "jmlog.h"
#include "watch.h"
#include "users.h"
#include "global.h"
#include "chenggong.h"
#include <QSound>

Travel T1;
vector<int> p1;

searcha::searcha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searcha)
{
    ui->setupUi(this);
}

searcha::~searcha()
{
    delete ui;
}

void searcha::on_pushButton_2_clicked()//关闭界面
{
    QSound *button=new QSound(":/b.wav");//声音显示
    button->play();
    t=t-t1;//将查找路线时间减去
    close();
}

void searcha::on_pushButton_clicked()//查找函数
{
    if(ui->a->isChecked()||ui->b->isChecked()||ui->c->isChecked())
    {
        QSound *button=new QSound(":/b.wav");//声音
        button->play();
        QString s1=ui->startcity->text();
        QString s2=ui->endcity->text();
        QString s3=ui->strttime->text();
        QString s4=ui->cost->text();
        int b=Backcity(s2);
        int a=Backcity(s1);
        int c=Backtime(s3);
        int L=Backtime(s4);
        vector<Road> line;
        vector<int> p;
        p.push_back(a);
        for(int i=0;i<p1.size();i++){
            p.push_back(p1[i]);//存入中途城市
        }
        p1.clear();
        p.push_back(b);
        string s,b1;
        if(ui->b->isChecked()){//调用函数，查找路线
            T1 = pivot_inW(g,p,s);
            b1="价格最优";
        }
        else if(ui->a->isChecked()){
            T1 = pivot_inT(g,p,c,s);
            b1="时间最优";
        }
        else if(ui->c->isChecked()){
            T1 =pivot_in_limit(g,p,c,L,s);
            b1="一定价格时间最优";
        }
        T1.first.second=name;//将路线储存在TR中
        TR.push_back(T1);
        QString ss= QString::fromStdString(s);//转换
        int c1=t;
        searchlog(s,b1,c1);//记录
        luxian *l=new luxian(this);
        l->show();//路线界面
        l->Print(ss);
    }
}

void searcha::on_pushButton_3_clicked()//设置中途城市
{
    QSound *button=new QSound(":/b.wav");//城市
    button->play();
    if(ui->A->isChecked())//暂存中途城市
        p1.push_back(0);
    else if(ui->B->isChecked())
        p1.push_back(1);
    else if(ui->C->isChecked())
        p1.push_back(2);
    else if(ui->D->isChecked())
        p1.push_back(3);
    else if(ui->E->isChecked())
        p1.push_back(4);
    else if(ui->F->isChecked())
        p1.push_back(5);
    else if(ui->G->isChecked())
        p1.push_back(6);
    else if(ui->H->isChecked())
        p1.push_back(7);
    else if(ui->I->isChecked())
        p1.push_back(8);
    else if(ui->J->isChecked())
        p1.push_back(9);
    else if(ui->K->isChecked())
        p1.push_back(10);
    chenggong *c=new chenggong(this);
    c->show();//添加成功界面
}
