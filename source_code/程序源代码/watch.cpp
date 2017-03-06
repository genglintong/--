#include "watch.h"
#include "ui_watch.h"
#include<QImage>
#include<QPixmap>
#include<QLabel>
#include<QFileDialog>
#include<QPainter>
#include "login.h"
#include <QBitmap>
#include <QPicture>
#include <QDebug>
#include <QWidget>
#include "graph.h"
#include "global.h"
#include "plan.h"

vector <Road> line;
int K=1;

watch::watch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::watch)
{
    ui->setupUi(this);
    id2=startTimer(1000);
}

watch::~watch()
{
    delete ui;
}

void change(int a,int &m,int &n){//城市坐标
    if(a==0){
        m=885;
        n=184;
    }
    else if(a==1){
        m=772;
        n=312;
    }
    else if(a==2){
        m=870;
        n=430;
    }
    else if(a==3){
        m=770;
        n=560;
    }
    else if(a==4){
        m=730;
        n=454;
    }
    else if(a==5){
        m=679;
        n=307;
    }
    else if(a==6){
        m=338;
        n=451;
    }
    else if(a==7){
        m=383;
        n=268;
    }
    else if(a==8){
        m=513;
        n=381;
    }
    else if(a==9){
        m=839;
        n=185;
    }
    else if(a==10){
        m=653;
        n=453;
    }
    return;
}

void coordinate(int t1,int &m,int &n,int &z){//计算当时坐标
    int a1,b1,a2,b2,p=0,q;//p上一次结束时间
    float c,d;
    if(t<t1)//未到时间
        return;
    int t2=t1;
    p=t1%24;
    for(int i=1;i<line.size();i++){
        int a=line[i].second.StartTime;
        int b=line[i].second.EndTime;
        if(p>a)
            t1=t1+b-p+24;
        else if(a>b)
            t1=t1+b+24-p;
        else
            t1=t1+b-p;
        p=b;
    }
    qDebug()<<t1;
    if(t1<t){
        z=-1;//释放路线标志
        return;//路线完成
    }
    p=0;
    q=t-t2+t2%24;
    //qDebug()<<q;
    for(int i=1;i<line.size();i++){
        int a=line[i].second.StartTime;
        int b=line[i].second.EndTime;

        if(a<p)
            q=q-24;
        p=b;
        //qDebug()<<q<<a<<b;
        a=a*K;
        b=b*K;
        if(q>=a&&q<=b){
            change(line[i-1].first,a1,b1);
            change(line[i].first,a2,b2);
            qDebug()<<a1<<b1<<a2<<b2;
            c=((float)(a2-a1))/((float)(b-a));
            d=((float)(b2-b1))/((float)(b-a));
            m=(q-a)*c+a1-25;
            n=(q-a)*d+b1-21;
            z=line[i].second.mean;
            return;
        }
    }
}

void watch::timerEvent(QTimerEvent *event)
{
    QString s,s1,s2;
    int a,b;
    if(event->timerId()==id2)
    {
        int tt=t/K;
        a=tt/24;
        b=tt%24;
        s1=QString::number(a,10);
        s2=QString::number(b,10);
        s=s1+"天"+s2+"时";
        ui->label_2->setText(s);
        update();
    }
}

void watch::paintEvent(QPaintEvent *event)//绘图事件
{
    setFixedSize(1200,700);
    int m=0,n=0,z=0;

    QPainter painter(this);
    QImage image,i,image1,image2;
    QRectF target(20,50,1160,630);
            //通过改变其坐标进而改变交通工具位置。

    //加载一张图片
    image.load(":/Image/d.png");//载入飞机图片
    image1.load(":/Image/e.png");//载入火车图片
    image2.load(":/Image/f.png");//载入汽车图片
    i.load(":/Image/地图");
    //在界面上绘制图片
    painter.drawImage(target, i);

    if(name!=""){//管理员，查找所有状态
       for(int i=0;i<TR.size();i++){
          if(TR[i].first.second==name){
              line=TR[i].second;
              int t1=TR[i].first.first;
              coordinate(t1,m,n,z);
              qDebug()<<t1<<t<<m<<n;
              QRectF ta(m,n,50,50);
              qDebug()<<"mmm"<<z;
              if(z==-1)
                  TR.erase(TR.begin()+i);
              if(z==2)
                 painter.drawImage(ta, image);
              else if(z==3)
                  painter.drawImage(ta, image1);
              else if(z==1)
                  painter.drawImage(ta, image2);
          }
       }
    }
    else{//用户，只观察用户状态
        for(int i=0;i<TR.size();i++){
               line=TR[i].second;
               coordinate(t,m,n,z);
               QRectF ta(m,n,50,50);
               qDebug()<<"mmm"<<z;
               if(z==-1)
                   TR.erase(TR.begin()+i);
               if(z==2)
                  painter.drawImage(ta, image);
               else if(z==3)
                   painter.drawImage(ta, image1);
               else if(z==1)
                   painter.drawImage(ta, image2);
        }
    }

}

void watch::mousePressEvent(QMouseEvent *e){//鼠标事件
    if(e->button()==Qt::LeftButton){
        qDebug()<<e->pos().x();
        qDebug()<<e->pos().y();
    }
}
