#include<iostream>
#include<cmath>
#include<climits>
#include<vector>

using namespace std;

void  printSubsetSum(vector<int>& arr,int sum ,vector<int>& subset,int n,int index){

    if(sum == 0){
        for(int i=0;i<index;i++){
            cout << subset[i] << " ";
        }
        cout<< endl;
        return;
    }

    if(sum<0 || n==0){
        return;
    }
    subset[index] = arr[n-1];
    printSubsetSum(arr,sum-arr[n-1],subset,n-1,index +1);
    printSubsetSum(arr,sum,subset,n-1,index);
}

int main(){
    int n =4;
    vector<int>arr(4);
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;

    int sum = 6;
    vector<int> subset(n);
    printSubsetSum(arr,sum,subset,n,0);
}