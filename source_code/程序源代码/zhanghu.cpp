#include<iostream>
#include<string>
#include<fstream>
#include "jmlog.h"
#include "watch.h"
using namespace std;

int  judge(string a,string b,string c)//判断账户是否注册
{
    ifstream in("mima.txt");
    string A,B,C;
    while(getline(in,A))
    {
        getline(in,B);
        getline(in,C);
        cout<<A<<B<<C<<endl;
        if(A==a&&B==b&&C==c)
        return 1;
    }
    in.close();
    return 0;
}
void write(string a,string b,string c)//注册账户
{
    if(c=="user")
        usercome(a,t,2);
    else if(c=="admin")
        usercome(a,t,3);
    ofstream out;
    out.open("mima.txt",ios::app);
    out<<a<<endl;
    out<<b<<endl;
    out<<c<<endl;
    out.close();
}
