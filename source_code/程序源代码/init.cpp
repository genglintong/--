#include "Init.h"
#include<QTextCodec>
#include<QDebug>

using namespace std;

int ToInt(char s[10]){//字符变整数
    int m=0;
    for(int i=0;s[i]!='\0';i++)
        m=m*10+s[i]-'0';
    return m;
}

void Print(Graph g){//输出所有路线
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("GB2312"));
    qDebug()<<"Starttime  终止城市  交通方式  价    格  起始时间  到达时间   "<<endl;
    for(int i=0;i<NN;i++){//遍历读出图
        for(int j=0;j<NN;j++){
            for(int z=0;z<g.P[i][j].i;z++){
                qDebug()<<left;//调试信息
                qDebug()<<i<<" "<<j
                        <<" "<<g.P[i][j].Time[z].mean
                        <<" "<<g.P[i][j].Time[z].money
                        <<" "<<g.P[i][j].Time[z].StartTime
                        <<" "<<g.P[i][j].Time[z].EndTime;
                qDebug()<<endl;
            }
        }
     }
}

Graph Read(void){//读文件入图
     ifstream Read("A.txt");//打开文件
     char s[20];//变量声明
     int m,z=0,n=0;
     Graph g;

     for(int i=0;i<NN;i++){//初始化图
        for(int j=0;j<NN;j++){
            for(int z=0;z<30;z++){
                g.P[i][j].Time[z].mean=-1;
                g.P[i][j].Time[z].money=-1;
                g.P[i][j].Time[z].StartTime=-1;
                g.P[i][j].Time[z].EndTime=-1;
                g.P[i][j].Time[z].Time=-1;
            }
            g.P[i][j].i=0;
        }
     }

     int i=0,j=0;

     if(!Read){//文件打开失败
         qDebug()<<"文件打开失败！！！"<<endl;
     }

     while(!Read.eof()){
        Read.getline(s,10,',');//读的第一个字符为换行
        if(Read.eof())
           break;
        if(z==0){
            i=s[0]-'A';
            z++;
        }
        else{
            i=s[1]-'A';
            z++;
        }
        //qDebug()<<"("<<s<<")"<<endl;
        Read.getline(s,10,',');
        j=s[0]-'A';

        Read.getline(s,10,',');
        m=ToInt(s);
        n=g.P[i][j].i;

        g.P[i][j].Time[n].mean=m;

        Read.getline(s,10,',');
        m=ToInt(s);

        g.P[i][j].Time[n].money=m;
        Read.getline(s,10,',');
        m=ToInt(s);

        g.P[i][j].Time[n].StartTime=m;
        Read.getline(s,10,',');
        m=ToInt(s);

        g.P[i][j].Time[n].EndTime=m;

        g.P[i][j].i=n+1;
        if(g.P[i][j].Time[n].EndTime>=g.P[i][j].Time[n].StartTime)
            g.P[i][j].Time[n].Time=g.P[i][j].Time[n].EndTime-g.P[i][j].Time[n].StartTime;
        else
            g.P[i][j].Time[n].Time=g.P[i][j].Time[n].EndTime-g.P[i][j].Time[n].StartTime+24;
     }
     Read.close();//文件关闭
     return g;
}


