#include<iostream>
#include<climits>
#include<algorithm>
#include<vector>

using namespace std;

int maxCrossingSum(int arr[],int l,int m,int h){
    int right_sum = INT_MIN;
    int left_sum = INT_MIN;
    
    int sum = 0;
    for(int i = m ; i<=l;i++){
        sum = sum + arr[i];
        if(sum > left_sum){
            left_sum = sum;
        }
    }

    sum = 0;
    for(int j = m+1 ;j<= h;j++){
        sum += arr[j];
        if(sum > right_sum){
            right_sum = sum;
        }
    }

    return (left_sum + right_sum);

}

int maxSumSubarray(int arr[],int l ,int h){
    if(l == h){
        return arr[l];
    }
        int m = (l+h)/2;
        int LS = maxSumSubarray(arr,l,m);
        int RS = maxSumSubarray(arr,m+1,h);
        int CS = maxCrossingSum(arr,l,m,h);
    return max(max(LS,RS),CS);
}

int main(){
    int arr[] = {1,2,3,-1,-3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    int max_sum = maxSumSubarray(arr,0,n-1);
    cout << max_sum << endl;

    return 0;
}