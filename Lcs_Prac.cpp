#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int LCS(const string& seq1, const string& seq2) {
    int m = seq1.length();
    int n = seq2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // Initialize all elements to 0

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(seq1[i-1] == seq2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    string seq1 = "AGGTAB";
    string seq2 = "GXTXAYB";

    cout << "Length of Longest Common Subsequence: " << LCS(seq1, seq2) << endl;

    return 0;
}
