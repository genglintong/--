#ifndef GRAPH_H
#define GRAPH_H
//数据结构
#define NN 11
#define V 11
#include<bits\stdc++.h>
using namespace std;
typedef struct{
    int mean;//交通方式
    int money;//该车次所需价格
    int StartTime;//该车次起始时间
    int EndTime;//该车次到达时间
    int Time;//该车运行时间
}TIME;

typedef struct {
    TIME Time[30];//一天最多一条路线十趟车，包含起始时间与到达时间
    int i;//路线个数
}Path;

typedef struct {
    Path P[NN][NN];
}Graph;

typedef pair <int,TIME> Road;//路线

typedef pair <int,string> TB;

typedef pair <TB,vector<Road> > Travel;//旅行路线

#endif // GRAPH_H

