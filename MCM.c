#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


void matrixChainMultiplication(int dimension[], int n) {
    int dp[n][n];
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
                }
            }
        }
    }
    
    printf("Minimum scalar multiplications needed: %d\n", dp[1][n - 1]);
}

int main() {
    int dimension[] = {4, 10, 3, 12, 15};
    int n = sizeof(dimension) / sizeof(dimension[0]);
    
    matrixChainMultiplication(dimension, n);

    return 0;
}
