#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
#define INF 1000000000
using namespace std;


void floydWarshall(vector<vector<int> >graph ,int n){
    vector<vector<int> >dist = graph;

    for(int k = 0;k<n;k++){
        for(int i =0;i<n;i++){
            for(int j =0;i<n;i++){
                if(dist[i][k] != INF && dist[k][j] != INF && dist[k][j] && dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for(int i =0;i<n;i++){
        if(dist[i][i] < 0){
            dist[i][i] = 0;
        }
    }

    for(int i = 0;i<n;i++){
        for(int j =0;j<n;j++){
            if(dist[i][j] == INF){
                cout << "INF";
            }else{
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

}
int main() {
    int n, m;
    cout << "Please enter the value of n and m:\n";
    cin >> n >> m;
    vector<vector<int> > graph(n+1, vector<int>(n+1, INF));

    cout << "Enter the start(u) and end(v) vertex along with capacity(w):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
    }

    cout << "The n*n matrix is :\n";
    floydWarshall(graph, n);

    return 0;
}