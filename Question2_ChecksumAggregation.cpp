#include <bits/stdc++.h>
using namespace std;

long long computeChecksumAggregation(long long n) {
    const long long MOD = 1000000007LL;
    long long ans = 0;

    // C(i,j) is symmetric: C(i,j) = C(j,i).
    // Calculate only i > j, then multiply by 2.
    for (long long j = 1; j <= n; ++j) {
        long long q = n / j;
        long long r = n % j;

        // Sum of i % j for i = 1..n.
        long long total =
            q * j * (j - 1) / 2 +
            r * (r + 1) / 2;

        // Remove the contribution for i <= j.
        total -= j * (j - 1) / 2;

        // For i > j, j % i = j.
        total += (n - j) * j;

        ans = (ans + total) % MOD;
    }

    return (2 * ans) % MOD;
}

int main() {
    cout << computeChecksumAggregation(2) << '\n';
    cout << computeChecksumAggregation(3) << '\n';
    cout << computeChecksumAggregation(4) << '\n';
    return 0;
}