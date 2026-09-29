#include <bits/stdc++.h>
using namespace std;

string plusMult(vector<long long> A) {
    int n = (int)A.size();

    // Only parity is required, so every value can be reduced modulo 2.
    auto calculate = [&](int start) -> int {
        vector<int> v;
        for (int i = start; i < n; i += 2) {
            v.push_back((int)((A[i] % 2 + 2) % 2));
        }

        if (v.empty()) return 0;
        if (v.size() == 1) return v[0];

        int result = v[0] * v[1] % 2;

        // Operations alternate: +, *, +, *, ...
        for (int i = 2; i < (int)v.size(); ++i) {
            if (i % 2 == 0)
                result = (result + v[i]) % 2;
            else
                result = (result * v[i]) % 2;
        }
        return result;
    };

    int R_even = calculate(0);
    int R_odd  = calculate(1);

    if (R_even > R_odd) return "EVEN";
    if (R_odd > R_even) return "ODD";
    return "NEUTRAL";
}

int main() {
    vector<long long> A = {2, 3, 5, 7, 13, 12};
    cout << plusMult(A) << endl;
    return 0;
}
