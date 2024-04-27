#include<iostream>
#include<climits>

using namespace std;

int maxCrossingSum(int arr[], int l, int m, int h) {
    int left_sum = INT_MIN;
    int right_sum = INT_MIN;


    int sum = 0;
    for(int i = m; i >= l; i--) {
        sum += arr[i];
        if(sum > left_sum) {
            left_sum = sum;
        }
    }

    sum = 0;
    for(int i = m + 1; i <= h; i++) {
        sum += arr[i];
        if(sum > right_sum) {
            right_sum = sum;
        }
    }

    return left_sum + right_sum;
}

int maxSumSubarray(int arr[], int l, int h) {
    if(l == h) {
        return arr[l];
    }

    int m = (l + h) / 2;

    int left_sum = maxSumSubarray(arr, l, m);
    int right_sum = maxSumSubarray(arr, m + 1, h);
    int crossing_sum = maxCrossingSum(arr, l, m, h);

    return max(max(left_sum, right_sum), crossing_sum);
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = maxSumSubarray(arr, 0, n - 1);
    cout << "Maximum subarray sum: " << max_sum << endl;
    return 0;
}
