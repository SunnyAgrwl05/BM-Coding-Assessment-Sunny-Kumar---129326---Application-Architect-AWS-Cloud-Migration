#include <bits/stdc++.h>
using namespace std;

long long maximumXorSum(const vector<int>& arr1, const vector<int>& arr2) {
    const long long MOD = 1000000007LL;
    int n = (int)arr1.size();
    long long ans = 0;

    // Process every bit independently.
    for (int bit = 0; bit < 31; ++bit) {
        long long mask = 1LL << bit;
        long long ones1 = 0, ones2 = 0;

        for (int x : arr1)
            if (x & mask) ++ones1;

        for (int x : arr2)
            if (x & mask) ++ones2;

        // XOR bit is 1 when the two bits are different.
        long long pairs =
            ones1 * (n - ones2) +
            (n - ones1) * ones2;

        ans = (ans + (pairs % MOD) * (mask % MOD)) % MOD;
    }

    return ans;
}

int main() {
    vector<int> arr1 = {1, 2, 3};
    vector<int> arr2 = {10, 10, 10};

    cout << maximumXorSum(arr1, arr2) << endl;
    return 0;
}