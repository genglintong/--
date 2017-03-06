#include "plan.h"
#include<QDebug>
#include<QString>
#include<QTextCodec>
#include<QString>

using namespace std;

int Backcity(QString s){
    int a;
    if(s=="哈尔滨")
        a=0;
    else if(s=="北京")
        a=1;
    else if(s=="上海")
        a=2;
    else if(s=="广州")
        a=3;
    else if(s=="武汉")
        a=4;
    else if(s=="呼和浩特")
        a=5;
    else if(s=="拉萨")
        a=6;
    else if(s=="乌鲁木齐")
        a=7;
    else if(s=="西宁")
        a=8;
    else if(s=="福州")
        a=9;
    else if(s=="重庆")
        a=10;

    return a;
}

int Backtime(QString s){
    return s.toInt();
}

string Changecity(int a){
    string s;
    if(a==0)
        s="哈尔滨";
    else if(a==1)
        s="北京";
    else if(a==2)
        s="上海";
    else if(a==3)
        s="广州";
    else if(a==4)
        s="武汉";
    else if(a==5)
        s="呼和浩特";
    else if(a==6)
        s="拉萨";
    else if(a==7)
        s="乌鲁木齐";
    else if(a==8)
        s="西宁";
    else if(a==9)
        s="福州";
    else if(a==10)
        s="重庆";
    return s;
}

string Changetime(int m)
{
      QString ss = QString::number(m);
      string s=ss.toStdString();
      return s;
}

//function for comp
bool fn(TIME a, TIME b){
    return(a.money < b.money);
}

// Number of vertices in the graph

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (sptSet[v] == false && dist[v] <= min)
         min = dist[v], min_index = v;

   return min_index;
}

TIME my_min(Path p, int preT)
{
    TIME t;
    int pt;
    t = p.Time[0];

    for(int k = 0; k < p.i; ++k){
        if(p.Time[k].StartTime > preT && p.Time[k].Time < t.Time){
            t = p.Time[k];
        }
    }
    return t;
}
int Low_T(vector<Road> line)
{
    int T = 0;
    Road p;
    for(int i = 0; i < line.size(); ++i){
        p = line[i];
        T = T + line[i].second.Time;
    }

    return T;
}
TIME my_min_lim(Path p, int preT, int limit)
{
    TIME t;
    int lim = limit;
    t = p.Time[0];

    for(int k = 0; k < p.i; ++k){
        if(p.Time[k].StartTime > preT && p.Time[k].money < t.money
            && p.Time[k].Time < limit){
            t = p.Time[k];
        }
    }
    return t;
}
// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
vector<Road> dijkstraCost(Graph graph, int src, int dst)
{
    int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
    vector<int> pre[V];
    vector<TIME> route[V];
    vector<TIME> line;
    stack<int> pathNode;
    stack<TIME> pathEdge;
    //pair<int,TIME> load;
    vector<Road> path;

    bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
     // Initialize all distances as INFINITE and stpSet[] as false
    for(int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     // Distance of source vertex from itself is always 0
    dist[src] = 0;

     // Find shortest path for all vertices
    for(int count = 0; count < V; count++){
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
        int u = minDistance(dist, sptSet);

       // Mark the picked vertex as processed
        sptSet [u] = true;
        for(int v = 0; v < V; v++){
            if(graph.P[u][v].i > 0){
                TIME t = *min_element(graph.P[u][v].Time, graph.P[u][v].Time+graph.P[u][v].i, fn);
                //TIME t = my_min(graph.P[u][v], preT);
                //int t_time = t.time;
                if(!sptSet[v] && dist[u] != INT_MAX && dist[u]+t.money < dist[v]){
                    dist[v] = dist[u] + t.money;
                    pre[v].clear();
                    pre[v].push_back(u);
             //	pre[v] = u;
                    route[v].clear();
                    route[v].push_back(t);
                //preT = preT + t.Time;
                }
            }
        }
    }
    TIME l = route[dst][0];
    int d = dst;
    while(!pre[d].empty()){
        pathNode.push(d);
        pathEdge.push(l);
        d = pre[d][0];
        if(d != src)
        l = route[d][0];
    }
    pathNode.push(d);

    Road p;
    pathNode.pop();
    while(!pathNode.empty() && !pathNode.empty()){
        //cout<<pathNode.top()<<" "<<endl;
        p.first = pathNode.top();
        p.second = pathEdge.top();
        path.push_back(p);
        pathNode.pop();
        pathEdge.pop();
    }
     //path in the vector-->line
     //line 中保存路径TIME
/*	 while(!pathEdge.empty()){
         TIME t = pathEdge.top();

         cout<<t.StartTime<<"--"<<t.EndTime<<endl;
         line.push_back(t);
         pathEdge.pop();
         }
*/
    //for(vector<Road>::iterator i = path.begin(); i != path.end(); ++i){
    //	cout<<(*i).first<<"--"<<(*i).second.StartTime<<endl;
    //}
    //qDebug()<<1;
    return path;
}

vector<Road> dijkstraTime(Graph graph, int src, int dst, int T)
{
    int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
    vector<int> pre[V];
    vector<TIME> route[V];
    vector<TIME> line;
    stack<int> pathNode;
    stack<TIME> pathEdge;
    //pair<int,TIME> load;
    vector<Road> path;

    bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
    int preT = T;
     // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

     // Distance of source vertex from itself is always 0
     dist[src] = 0;

     // Find shortest path for all vertices
     for (int count = 0; count < V; count++){
       // Pick the minimum distance vertex from the set of vertices not
       // yet processed. u is always equal to src in first iteration.
       int u = minDistance(dist, sptSet);

       // Mark the picked vertex as processed
        sptSet [u] = true;
        for(int v = 0; v < V; v++){
            if(graph.P[u][v].i > 0){
                //TIME t = *min_element(graph.P[u][v].Time, graph.P[u][v].Time+graph.P[u][v].i, fn);
                TIME t = my_min(graph.P[u][v], preT);
                //int t_time = t.time;
                if(!sptSet[v] && dist[u] != INT_MAX && dist[u]+t.Time < dist[v]){
                dist[v] = dist[u] + t.Time;
                pre[v].clear();
                pre[v].push_back(u);
             //	pre[v] = u;
                route[v].clear();
                route[v].push_back(t);
                preT = (preT + t.Time)%24;
                }
            }
        }
     }
    TIME l = route[dst][0];
    int d = dst;
    while(!pre[d].empty()){
        pathNode.push(d);
        pathEdge.push(l);
        d = pre[d][0];
        if(d != src)
        l = route[d][0];
    }
    pathNode.push(d);
    //pathEdge.push(l);
     // print the constructed distance array
     //printSolution(dist, V);
     Road p;
     pathNode.pop();
     while(!pathNode.empty() && !pathNode.empty()){
         cout<<pathNode.top()<<" "<<endl;
         p.first = pathNode.top();
         p.second = pathEdge.top();
         path.push_back(p);
         pathNode.pop();
         pathEdge.pop();
     }
     //path in the vector-->line
     //line 中保存路径TIME
     while(!pathEdge.empty()){
         TIME t = pathEdge.top();

         cout<<t.StartTime<<"--"<<t.EndTime<<endl;
         line.push_back(t);
         pathEdge.pop();
         }

    //for(vector<Road>::iterator i = path.begin(); i != path.end(); ++i){
    //	cout<<(*i).first<<"--"<<(*i).second.StartTime<<endl;
    //}
    return path;
}

vector<Road> dijkstraCost_T(Graph graph, int src, int dst, int T, int L)
{
    int dist[V];     // The output array.  dist[i] will hold the shortest
                      // distance from src to i
    vector<int> pre[V];
    vector<TIME> route[V];
    vector<TIME> line;
    stack<int> pathNode;
    stack<TIME> pathEdge;
    //pair<int,TIME> load;
    vector<Road> path;

    bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
                     // path tree or shortest distance from src to i is finalized
    int preT = T;
    int limit = L;
     // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < V; count++){
    // Pick the minimum distance vertex from the set of vertices not
    // yet processed. u is always equal to src in first iteration.
        int u = minDistance(dist, sptSet);

       // Mark the picked vertex as processed
        sptSet [u] = true;
        for(int v = 0; v < V; v++){
            if(graph.P[u][v].i > 0){
                //TIME t = *min_element(graph.P[u][v].Time, graph.P[u][v].Time+graph.P[u][v].i, fn);
                TIME t = my_min_lim(graph.P[u][v], preT, limit);
                //int t_time = t.time;

                if(!sptSet[v] && dist[u] != INT_MAX && dist[u]+t.Time < dist[v]){
                    dist[v] = dist[u] + t.Time;
                    pre[v].clear();
                    pre[v].push_back(u);
                    route[v].clear();
                    route[v].push_back(t);
                    preT = (preT + t.Time) % 24;
                    limit = limit - t.Time;
                }
            }
        }
    }
    TIME l = route[dst][0];
    int d = dst;
    while(!pre[d].empty()){
        pathNode.push(d);
        pathEdge.push(l);
        d = pre[d][0];
        if(d != src)
        l = route[d][0];
    }
    pathNode.push(d);

    Road p;
    pathNode.pop();
    while(!pathNode.empty() && !pathNode.empty()){
     //	cout<<pathNode.top()<<" "<<endl;
        p.first = pathNode.top();
        p.second = pathEdge.top();
        path.push_back(p);
        pathNode.pop();
        pathEdge.pop();
    }
    return path;
}

Travel pivot_inT(Graph graph, vector<int>p, int T,string &s)
{
    int src = p[0];
    int cnt = p.size();
    int  preT = T;
    vector<Road> line;
    vector<Road> path;
    Travel tr;
    tr.first.first = t-t1;
    tr.first.second = s;
    for(int i = 0; i < cnt-1; ++i){
        path = dijkstraTime(graph, p[i], p[i+1], preT);
        if(i == 0){
            line = path;
        }
        else{
            line.insert(line.end(),path.begin(),path.end());
        }
        int t = line.size();
        preT = line[t-1].second.EndTime;
    }


    Road pp;
    pp.first = p[0];
    path.clear();
    path.push_back(pp);
    line.insert(line.begin(),path.begin(),path.end());
    for(int i=1;i<line.size();i++){
        s=s+Changecity(line[i-1].first)+" -- ";
        s=s+Changecity(line[i].first);
        s=s+"   ";
        int q=line[i].second.mean;
        if(q==1)
            s=s+"汽车";
        else if(q==2)
            s=s+"飞机";
        else if(q==3)
            s=s+"火车";
        s=s+"   ";
        s=s+Changetime(line[i].second.StartTime);
        s=s+" -- ";
        s=s+Changetime(line[i].second.EndTime);
        s=s+"    ";
        s=s+Changetime(line[i].second.money);
        s=s+"\n";
    }
    tr.second = line;
    return tr;

}
Travel pivot_inW(Graph graph, vector<int>p,string &s)
{
    int src = p[0];
    int cnt = p.size();
    //int  preT = T;
    vector<Road> line;
    vector<Road> path;
    Travel tr;
    tr.first.first = t-t1;
    tr.first.second = s;

    for(int i = 0; i < cnt-1; ++i){
        path = dijkstraCost(graph, p[i], p[i+1]);
        if(i == 0){
            line = path;
        }
        else{
            line.insert(line.end(),path.begin(),path.end());
        }
        int t = line.size();
        //preT = line[t-1].second.EndTime;
    }
    qDebug()<<1;
    Road pp;
    pp.first = p[0];
    path.clear();
    path.push_back(pp);
    line.insert(line.begin(),path.begin(),path.end());
    for(int i=1;i<line.size();i++){
        s=s+Changecity(line[i-1].first)+" -- ";
        s=s+Changecity(line[i].first);
        s=s+"   ";
        int q=line[i].second.mean;
        if(q==1)
            s=s+"汽车";
        else if(q==2)
            s=s+"飞机";
        else if(q==3)
            s=s+"火车";
        s=s+"   ";
        s=s+Changetime(line[i].second.StartTime);
        s=s+" -- ";
        s=s+Changetime(line[i].second.EndTime);
        s=s+"    ";
        s=s+Changetime(line[i].second.money);
        s=s+"\n";
    }
    tr.second = line;
    return tr;

}
Travel pivot_in_limit(Graph graph, vector<int>p, int T, int L,string &s)
{
    int src = p[0];
    int cnt = p.size();
    int  preT = T;
    string s1;
    vector<Road> line = pivot_inT(graph, p, T,s1).second;
    vector<Road> path;
    Travel tr;
    tr.first.first = t-t1;
    tr.first.second = s;

    int lowT = Low_T(line);

    if(L >= lowT){
        for(int i = 0; i < cnt-1; ++i){
            path = dijkstraCost_T(graph, p[i], p[i+1], preT, L/cnt);
            if(i == 0){
                line = path;
            }
            else{
                line.insert(line.end(),path.begin(),path.end());
            }
            int t = line.size();
            preT = line[t-1].second.EndTime;
        }
    }
    Road pp;
    pp.first = p[0];
    path.clear();
    path.push_back(pp);
    line.insert(line.begin(),path.begin(),path.end());
    for(int i=1;i<line.size();i++){
        s=s+Changecity(line[i-1].first)+" -- ";
        s=s+Changecity(line[i].first);
        s=s+"   ";
        int q=line[i].second.mean;
        if(q==1)
            s=s+"汽车";
        else if(q==2)
            s=s+"飞机";
        else if(q==3)
            s=s+"火车";
        s=s+"   ";
        s=s+Changetime(line[i].second.StartTime);
        s=s+" -- ";
        s=s+Changetime(line[i].second.EndTime);
        s=s+"    ";
        s=s+Changetime(line[i].second.money);
        s=s+"\n";
    }
    tr.second = line;
    return tr;
}
