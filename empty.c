#include<iostream>

using namespace std;

void calcLPS(string p,int LPS[]){

    LPS[0]=0;

    int i=0,j=1;

    while (j<p.length())

    {

        if(p[i]==p[j]){

            LPS[j]=i+1;

            i++;j++;

        }

        else{

            if(i==0)

                LPS[j++]=0;



            else

                i=LPS[i-1];

        }

    }

   

}

int main(){



    string s,p;

    cout<<"Enter the string: ";

    cin>>s;

    cout<<"Enter the pattern: ";

    cin>>p;

    int slen=s.length();

    int plen=p.length();

    int LPS[plen];

    calcLPS(p,LPS);

    int i=0,j=0;

    while(i<slen){

        if(p[j]==s[i]){

            i++;j++;

        }

        if(j==plen){

            cout<<"Match found at index: "<<i-plen<<endl;

            j=LPS[j-1];

        }

        else if(p[j]!=s[i] && i<slen){

            if(j==0)

                i++;

            else

                j=LPS[j-1];

        }

    }



}


#include <iostream> #include <vector> #include <string> using namespace std;

void rabinKarpMatcher(const string& text, const string& pattern, int q) { int n = text.length(); int m = pattern.length(); int d = 10; int h = 1; for (int i = 0; i < m - 1; ++i) h = (h * d) % q; int p = 0; int t = 0; int matches = 0; int spurious_hits = 0; for (int i = 0; i < m; ++i) { p = (d * p + (pattern[i] - '0')) % q; t = (d * t + (text[i] - '0')) % q; } for (int i = 0; i <= n - m; ++i) { if (p == t) { int j; for (j = 0; j < m; ++j) { if (text[i + j] != pattern[j]) break; } if (j == m) { cout << "Pattern found at index " << i << endl; matches++; } else { spurious_hits++; } } if (i < n - m) { t = (d * (t - (text[i] - '0') * h) + (text[i + m] - '0')) % q; if (t < 0) t = (t + q); } } cout << "Total matches: " << matches << endl; cout << "Total spurious hits: " << spurious_hits << endl; } int main() { string text = "2359023141526739921"; string pattern = "31415"; int q = 13; rabinKarpMatcher(text, pattern, q); return 0; }



#include <stdio.h> #include <limits.h> #define INF INT_MAX #define MAX_NODES 100 int min(int a, int b) { return (a < b) ? a : b; } void floydWarshall(int graph[MAX_NODES][MAX_NODES], int n) { int dist[MAX_NODES][MAX_NODES]; int i, j, k; for (i = 0; i < n; i++) { for (j = 0; j < n; j++) { dist[i][j] = graph[i][j]; } } for (k = 0; k < n; k++) { for (i = 0; i < n; i++) { for (j = 0; j < n; j++) {

if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) { dist[i][j] = dist[i][k] + dist[k][j]; } } } } for (i = 0; i < n; i++) { for (j = 0; j < n; j++) { if (dist[i][j] == INF) { printf("INF "); } else { printf("%d ", dist[i][j]); } } printf("\n"); } } int main() { int n, m; printf("Please enter the value of n amd m:\n"); scanf("%d %d", &n, &m); int graph[MAX_NODES][MAX_NODES]; for (int i = 0; i < MAX_NODES; i++) { for (int j = 0; j < MAX_NODES; j++) { graph[i][j] = (i == j) ? 0 : INF; } } printf("Enter the start(u) and end(v) vertex along with capacity(w):\n"); for (int i = 0; i < m; i++) { int u, v, w; scanf("%d %d %d", &u, &v, &w); graph[u][v] = w; } printf("The n*n matrix is :\n"); floydWarshall(graph, n); return 0; }





include<cstdio> #include<queue> #include<cstring> #include<vector> #include<iostream> using namespace std; int c[10][10]; int flowPassed[10][10]; vector<int> g[10]; int parList[10]; int currentPathC[10]; int bfs(int sNode, int eNode) { memset(parList, -1, sizeof(parList)); memset(currentPathC, 0, sizeof(currentPathC)); queue<int> q; q.push(sNode); parList[sNode] = -1; currentPathC[sNode] = 999; while(!q.empty()) { int currNode = q.front(); q.pop(); for(int i=0; i<g[currNode].size(); i++) { int to = g[currNode][i]; if(parList[to] == -1) { if(c[currNode][to] - flowPassed[currNode][to] > 0) { parList[to] = currNode; currentPathC[to] = min(currentPathC[currNode],c[currNode][to] - flowPassed[currNode][to]); if(to == eNode) { return currentPathC[eNode]; } q.push(to); } } } } return 0; } int edmondsKarp(int sNode, int eNode) { int maxFlow = 0; while(true) { int flow = bfs(sNode, eNode); if (flow == 0) { break; } maxFlow += flow; int currNode = eNode; while(currNode != sNode) { int prevNode = parList[currNode]; flowPassed[prevNode][currNode] += flow; flowPassed[currNode][prevNode] -= flow; currNode = prevNode; } } return maxFlow; } int main() { int nodCount, edCount; cout<<"Enter the number of nodesNo and edges(m):\n"; cin>>nodCount>>edCount; int source, sink; cout<<"Enter the start(u) and end(v) vertex along with capacity(w):\n"; for(int ed = 0; ed < edCount; ed++) { int from, to, cap; cin>>from>>to>>cap; c[from][to] = cap; g[from].push_back(to);g[to].push_back(from); } cout<<"Enter the source and sink:\n"; cin>>source>>sink; int maxFlow = edmondsKarp(source, sink); cout<<endl<<"Max Flow is:"<<maxFlow<<endl; }