#include "add.h"
#include "ui_add.h"
#include "administrators.h"
#include "graph.h"
#include  <string>
#include "init.h"
#include "plan.h"
#include "chenggong.h"
#include <QSound>

using namespace std;

add::add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
}

add::~add()
{
    delete ui;
}

void add::on_pushButton_clicked()//添加路线函数
{
    QSound *button=new QSound(":/b.wav");//添加声音
    button->play();//声音显示
    int mean,money,starttime,endtime;//变量的定义
    int startcity,endcity;
    char aa='A',bb='A';
    ofstream change("A.txt",ios::app);//以在文档最后补加方式打开文件
    change<<endl;
    QString a=ui->startcity->text();//获取字符串
    startcity=Backcity(a);//转化为存取的形式
    aa=aa+startcity;
    change<<aa<<",";//添加进文件
    QString b=ui->endcity->text();//获取字符串
    endcity=Backcity(b);//转化为存取的形式
    bb=bb+endcity;
    change<<bb<<",";//添加进文件
    QString c=ui->mean->text();//获取字符串
    mean=0;
    if(c=="汽车")//转化为存取的形式
        mean=1;
    else if(c=="飞机")
        mean=2;
    else if(c=="火车")
        mean=3;
    change<<mean<<",";//添加进文件
    QString d=ui->money->text();//获取字符串
    money=d.toInt();//转化为存取的形式
    change<<money<<",";//添加进文件
    QString e=ui->starttime->text();//获取字符串
    starttime=e.toInt();//转化为存取的形式
    change<<starttime<<",";//添加进文件
    QString f=ui->endtime->text();//获取字符串
    endtime=f.toInt();//转化为存取的形式
    change<<endtime<<",";//添加进文件
    change.close();//关闭文件
    chenggong *cc=new chenggong(this);//new添加成功界面
    cc->show();//显示界面
}

void add::on_pushButton_2_clicked()//添加结束，重新将图读写进去
{
    QSound *button=new QSound(":/b.wav");//欢迎的声音
    button->play();
    Graph g;
    g=Read();//重新读写进图结构
    Print(g);
    close();//关闭界面
}
