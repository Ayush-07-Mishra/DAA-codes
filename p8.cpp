#include<iostream>
#include<vector>
#include<algorithm>

#define INF 1000000000
#define MAX_NODES 100

using namespace std;

void floydWarshall(vector<vector<int> >& graph ,int n){
    vector<vector<int> > dist = graph;

    for(int k =0;k<n;k++){
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(dist[i][k] != INF && dist[k][j != INF && (dist[i][j] > dist[i][k] + dist[k][j])]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    // check for the negative cycles
    for(int i=0;i<n;i++){
        if(disit[i][i] < 0){
            dist[i][i] =0;
        }
    }

    for(int i =0;i<n;i++){
        for(int j =0;j<m;j++){
            if(dist[i][j] == INF){
                cout<< "INF" ;
            }else{
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }
    
}

int main(){
    int n, m;
    cout << "enter the value of n and m";
    vector<vector<int> > graph(MAX_NODES,vector<int>(MAX_NODES,INF));

    cout << "enter the start(u) and the end (v) vertex along with capacity(w) :";

    for(int i =0;i<n;i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    cout<< "the n*n matrix is :\n";
    floydWarshall(graph,n); 
}