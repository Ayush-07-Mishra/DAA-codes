#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longest_common_subsequence_length(const string& seq1, const string& seq2) {
    int m = seq1.length();
    int n = seq2.length();

    // Create a 2D vector to store lengths of LCS for all subproblems
    vector<vector<int> > dp(m + 1, vector<int>(n + 1, 0));

    // Initialize the first row and column with zeros
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = 0;
    }

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

    // Length of the LCS
    return dp[m][n];
}

int main() {
    string seq1 = "AGGTAB";
    string seq2 = "GXTXAYB";

    cout << "Length of Longest Common Subsequence: " << longest_common_subsequence_length(seq1, seq2) << endl;

    return 0;
}
