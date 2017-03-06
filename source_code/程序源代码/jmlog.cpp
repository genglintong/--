#include "jmlog.h"
#include "graph.h"
//日志文件记录

using namespace std;

void usercome(string a,int c,int b){//记录用户到来
    ofstream out;
    out.open("1.txt",ios::app);//打开文件
    out<<"时间："<<c<<endl;
    if(b==0)
       out<<"用户"<<a<<"到来！"<<endl;
    else if(b==1)
        out<<"管理员"<<a<<"到来！"<<endl;
    else if(b==2)
        out<<"用户"<<a<<"注册成功！"<<endl;
    else if(b==3)
        out<<"管理员"<<a<<"注册成功！"<<endl;
    out.close();//关闭
}

void searchlog(string a,string b,int c){//输出文件记录
    ofstream out;
    out.open("1.txt",ios::app);
    out<<"时间："<<c<<endl;
    out<<"查找信息："<<a<<endl;
    out.close();
}

void jmclear(){//程序关闭，对日志文件进行清理
    ofstream out;
    out.open("1.txt",ios::out);
    out.close();
}
