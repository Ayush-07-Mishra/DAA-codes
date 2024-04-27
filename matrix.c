#include<stdio.h>
#include<limits.h>

void MCM(int dim[], int n) {
    int c[n][n];

    for(int i = 1; i < n; i++) {
        c[i][i] = 0;
    }

    for(int L = 2; L < n; L++) {
        for(int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            c[i][j] = INT_MAX;
            for(int k = i; k < j; k++) {
                int cost = c[i][k] + c[k + 1][j] + dim[i - 1] * dim[k] * dim[j];
                if(cost < c[i][j]) {
                    c[i][j] = cost;
                }
            }
        }
    }

    printf("%d\n", c[1][n - 1]);
}

int main() {
    int dimension[] = {4, 10, 3, 12, 15};
    int n = sizeof(dimension) / sizeof(dimension[0]);
    
    MCM(dimension, n);

    return 0;
}
