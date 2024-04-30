#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, string> longest_common_subsequence(const string& seq1, const string& seq2) {
    int m = seq1.length();
    int n = seq2.length();

    // Create a 2D vector to store lengths of LCS for all subproblems
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

    // Build the DP table bottom-up
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (seq1[i - 1] == seq2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    
    // Find the longest common subsequence
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (seq1[i - 1] == seq2[j - 1]) {
            lcs = seq1[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Length of the LCS and the LCS string
    return make_pair(dp[m][n], lcs);
}

int main() {
    string seq1 = "Longest";
    string seq2 = "Stone";

    pair<int, string> result = longest_common_subsequence(seq1, seq2);
    cout << "Length of Longest Common Subsequence: " << result.first << endl;
    cout << "Longest Common Subsequence: " << result.second << endl;

    return 0;
}
