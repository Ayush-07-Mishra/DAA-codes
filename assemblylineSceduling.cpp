#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int assemblyLineScheduling(vector<vector<int> >& a, vector<vector<int> >& t, vector<int>& e, vector<int>& x) {
    int n = a[0].size();
    vector<int> f1(n), f2(n);

    f1[0] = e[0] + a[0][0]; 
    f2[0] = e[1] + a[1][0]; 

    for (int i = 1; i < n; ++i) {
        f1[i] = min(f1[i - 1] + a[0][i], f2[i - 1] + t[1][i] + a[0][i]);
        f2[i] = min(f2[i - 1] + a[1][i], f1[i - 1] + t[0][i] + a[1][i]);
    }
    return min(f1[n - 1] + x[0], f2[n - 1] + x[1]);
}

int main() {
    vector<vector<int> > a(2, vector<int>(4));
    a[0][0] = 4;
    a[0][1] = 5;
    a[0][2] = 3;
    a[0][3] = 2;
    a[1][0] = 2;
    a[1][1] = 10;
    a[1][2] = 1;
    a[1][3] = 4; // Time taken at each station on each line

    vector<vector<int> > t(2, vector<int>(4));
    t[0][0] = 0;
    t[0][1] = 7;
    t[0][2] = 4;
    t[0][3] = 5;
    t[1][0] = 0;
    t[1][1] = 9;
    t[1][2] = 2;
    t[1][3] = 8; // Transfer time between stations

    vector<int> e(2);
    e[0] = 10;
    e[1] = 12; // Entry time for each line

    vector<int> x(2); 
    x[0] = 18;
    x[1] = 7; // Exit time for each line

    int minTime = assemblyLineScheduling(a, t, e, x);
    cout << "Minimum time to traverse the assembly lines: " << minTime << endl;

    return 0;
}
