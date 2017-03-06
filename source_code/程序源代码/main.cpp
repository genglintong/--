#include <QApplication>
#include "login.h"
#include "users.h"
#include "administrators.h"
#include<QTextCodec>
#include<QSound>
#include "init.h"
#include "plan.h"
#include "global.h"
#include <string.h>
#include <string>
#include "jmlog.h"

using namespace std;
Graph g;
vector<Travel> TR;
int t,t1;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
    QSound *sound=new QSound(":/sound.wav");

    g=Read();//初始化读入文件
    Print(g);
    //string s;
    //s=dijkstraCostW(g,1,2);
    sound->play();
    login l;
    l.show();
    jmclear();
    return a.exec();
}

