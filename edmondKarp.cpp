#include <iostream>
#include <queue>
#include <bits/stdc++.h>
using namespace std;

#define n 5
typedef struct node{
    int id,status,pred;
}node;

int res[n][n] = {{0,12,15,0,0},
                 {0,0,8,0,0},
                 {0,0,0,7,6},
                 {0,0,0,0,5},
                 {0,0,0,0,0}};

bool bfs(node vert[],node source,node sink)
{
    node u;
    int i,j;
    queue <node>q;
    for(i=0;i<n;i++)
    {
        vert[i].status = 0;
    }
    vert[source.id].pred = -1;
    vert[source.id].status = 1;
    q.push(source);

    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(res[u.id][i]!=0 && vert[i].status == 0){
                q.push(vert[i]);
                vert[i].status = 1;
                vert[i].pred = u.id;
            }
        }
    }
    return (vert[sink.id].status == 1);
}

int main(){
    int maxflow = 0;
    node vert[n],source,sink;
    for(int i=0 ; i<n ; i++)
        vert[i].id = i ; 
    source.id = 0;
    sink.id = n-1;
    int u,v;
    while( bfs(vert,source,sink)){
        int augflow = 99999;
        cout << endl <<"In path :";
        for(v=sink.id ; v != source.id ; v = vert[v].pred){
            cout << v <<" -> ";
            u = vert[v].pred;
            if(res[u][v] < augflow)
            {
                augflow = res[u][v];
            }
        }
        cout << source.id;
        for(v = sink.id ; v != source.id ; v = vert[v].pred)
        {
            u=vert[v].pred;
            res[u][v] -= augflow;
            res[v][u] += augflow;
        }
        maxflow += augflow;
    }
    cout<<endl<<"Maxflow is: "<< maxflow;
    return 0;
}