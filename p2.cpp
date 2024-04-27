#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

int maxCrossingSum(int arr[], int l, int m, int h) {
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;

    int sum = 0;
    for(int i = m; i >= l; i--) {
        sum += arr[i];
        if(sum > leftSum) {
            leftSum = sum;
        }
    }

    sum = 0;
    for(int i = m + 1; i <= h; i++) {
        sum += arr[i];
        if(sum > rightSum) {
            rightSum = sum;
        }
    }

    return leftSum + rightSum;
}

int maxSumSubarray(int arr[], int l, int h) {
    if(l == h) {
        return arr[l];
    }

    int m = (l + h) / 2;
    int leftSum = maxSumSubarray(arr, l, m);
    int rightSum = maxSumSubarray(arr, m + 1, h);
    int crossingSum = maxCrossingSum(arr, l, m, h);

    return max(max(leftSum, rightSum), crossingSum);
}

int main() {
    int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);
    int h = n - 1;

    cout << "Maximum subarray sum: " << maxSumSubarray(arr, 0, h) << endl;

    return 0;
}
