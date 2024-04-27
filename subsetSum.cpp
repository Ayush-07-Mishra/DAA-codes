#include <iostream>
#include <vector>
using namespace std;

void printSubsetSum(vector<int>& arr, int n, int sum, vector<int>& subset, int index) {
    if (sum == 0) {
        for (int i = 0; i < index; i++) {
            cout << subset[i] << " ";
        }
        cout << endl;
        return;
    }
    if (n == 0 || sum < 0) {
        return;
    }
    subset[index] = arr[n - 1];
    printSubsetSum(arr, n - 1, sum - arr[n - 1], subset, index + 1);
    printSubsetSum(arr, n - 1, sum, subset, index);
}

int main() {
    int n = 4;
    // cin >> n;
    vector<int> arr(4); // Initialize a vector of size 4
    arr[0] = 1; // Assign values individually
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;


    int d = 6;

    vector<int> subset(n);
    cout << "subset to get the sum : " << endl;
    printSubsetSum(arr, n, d, subset, 0);

    return 0;
}
