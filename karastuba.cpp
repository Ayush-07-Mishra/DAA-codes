#include <iostream>
#include <cmath>

using namespace std;


int length(long long num) {
    int len = 0;
    while (num > 0) {
        num /= 10;
        len++;
    }
    return len;
}

long long karatsuba(long long a, long long b) {
    
    if (a < 10 || b < 10) {
        return a * b;
    }

    int n = max(length(a), length(b));
    int m = n / 2;

    long long aH = a / (long long)pow(10, m);
    long long aL = a % (long long)pow(10, m);
    long long bH = b / (long long)pow(10, m);
    long long bL = b % (long long)pow(10, m);

    long long z0 = karatsuba(aL, bL);
    long long z2 = karatsuba(aH, bH);
    long long z1 = karatsuba(aH + aL, bH + bL) - z2 - z0;

    return (z2 * (long long)pow(10, 2 * m)) + (z1 * (long long)pow(10, m)) + z0;
}

int main() {
    long long a, b;
    cout << "Enter two numbers (a and b): ";
    cin >> a >> b;

    long long result = karatsuba(a, b);
    cout << "Result: " << result << endl;

    return 0;
}
