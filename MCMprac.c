#include<stdio.h>
#include<math.h>
#include<limits.h>
#include<stdlib.h>

void MCM(int dim[],int n){
    int dp[n][n];

    for(int i =1;i<n;i++){
        dp[i][i] = 0;
    }
    int j;
    for(int L =2;L<n;L++){
        for(int i =1;i<n-L+1;i++){
            j = i + L -1;
            dp[i][j] = INT_MAX;
            for(int k = i;k<j;k++){
                int cost = dp[i][k] + dp[k+1][j] + dim[i-1] * dim[k] * dim[j];
                if(cost < dp[i][j]){
                    dp[i][j] = cost;
                }
            }
        }
    }
    printf("%d",dp[1][n-1]);
}

int main(){
    int dim[] = {4,10,3,12,15};
    int n = sizeof(dim)/sizeof(dim[0]);

    MCM(dim,n);

    return 0;
}