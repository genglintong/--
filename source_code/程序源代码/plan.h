#ifndef PLAN_H
#define PLAN_H
//三种策略
#include "graph.h"
#include<string>
#include<QString>

using namespace std;

extern int t;//系统时间
extern int t1;//查询所花费时间

bool fn(TIME a, TIME b);//判断两路线优劣
int minDistance(int dist[], bool sptSet[]);//查找最短距离
int Low_T(vector<Road> line);//查找最短时间
TIME my_min(Path p, int preT);//最短路线
TIME my_min_lim(Path p, int preT, int limit);//有限制的最短路线
vector<Road> dijkstraCost(Graph graph, int src, int dst);
Travel pivot_inT(Graph graph, vector<int>p, int T,string &s);//以时间为标准的最短路线
vector<Road> dijkstraTime(Graph graph, int src, int dst, int T);
vector<Road> dijkstraCost_T(Graph graph, int src, int dst, int T, int L);//以价钱为标准的最短路线
Travel pivot_inW(Graph graph, vector<int>p,string &s);
Travel pivot_in_limit(Graph graph, vector<int>p, int T, int L,string &s);//一定价钱最短时间路线

string Changecity(int a);//将城市序号转化为汉字
string Changetime(int m);//将时间转化为字符串
int Backcity(QString s);//将汉字转化为城市所代表的数字
int Backtime(QString s);//将时间字符串转化为数字

#endif // PLAN_H

