#include<iostream>
#include<cmath>
#include<climits>

using namespace std;

int crossingsum(int arr[], int l, int m, int h) {
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
    for(int j = m + 1; j <= h; j++) {
        sum += arr[j];
        if(sum > right_sum) {
            right_sum = sum;
        }
    }

    return (left_sum + right_sum);
}

int maxsubarraysum(int arr[], int l, int h) {
    if(l == h) {
        return arr[l];
    } else {
        int m = (l + h) / 2;

        int LS = maxsubarraysum(arr, l, m);
        int RS = maxsubarraysum(arr, m + 1, h);
        int CS = crossingsum(arr, l, m, h);

        return max(max(LS, RS), CS);
    }
}

int main() {
    int l, h;
    int arr[] = {2, 4, 5, 6, 2, -4, 8, 1, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    h = n - 1;
    int max_sum = maxsubarraysum(arr, 0, h);
    cout << "Maximum subarray sum: " << max_sum << endl;
    return 0;
}
