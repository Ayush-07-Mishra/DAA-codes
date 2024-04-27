#include <iostream>
#include <vector>
#include <climits>
using namespace std;

pair<int, vector<vector<int> > > matrixChainMultiplication(vector<int>& dimension) {
    int n = dimension.size();
    vector<vector<int> > dp(n, vector<int>(n, 0));
    vector<vector<int> > splitIndex(n, vector<int>(n, 0));

    for (int i = 1; i < n; ++i) {
        dp[i][i] = 0;
    }

    for (int L = 2; L < n; ++L) {
        for (int i = 1; i < n - L + 1; ++i) {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + dimension[i - 1] * dimension[k] * dimension[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    splitIndex[i][j] = k;
                }
            }
        }
    }
    return make_pair(dp[1][n - 1], splitIndex);
}

void printOptimalParenthesization(vector<vector<int> >& splitIndex, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParenthesization(splitIndex, i, splitIndex[i][j]);
        printOptimalParenthesization(splitIndex, splitIndex[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    vector<int> dimension(5); 
    dimension[0] = 4;
    dimension[1] = 10;
    dimension[2] = 3;
    dimension[3] = 12;
    dimension[4] = 15;
    pair<int,vector<vector<int> > > result = matrixChainMultiplication(dimension);
    int minScalarMultiplications = result.first;
    vector<vector<int> > splitIndex = result.second;

    cout << "Minimum scalar multiplications needed: " << minScalarMultiplications << endl;
    cout << "Optimal parenthesization: ";
    printOptimalParenthesization(splitIndex, 1, dimension.size() - 1);
    cout << endl;

    return 0;
}

