#include <bits/stdc++.h>
using namespace std;

string plusMult(vector<long long> A) {
    auto calculate = [&](int start) -> long long {
        vector<long long> elements;

        for (int i = start; i < (int)A.size(); i += 2) {
            elements.push_back(A[i]);
        }

        if (elements.size() < 2)
            return elements.empty() ? 0 : elements[0] % 2;

        long long result = elements[0] * elements[1];

        for (int i = 2; i < (int)elements.size(); i++) {
            if (i % 2 == 0)
                result += elements[i];
            else
                result *= elements[i];
        }

        return ((result % 2) + 2) % 2;
    };

    long long R_even = calculate(0);
    long long R_odd = calculate(1);

    if (R_odd > R_even)
        return "ODD";
    else if (R_even > R_odd)
        return "EVEN";
    else
        return "NEUTRAL";
}

int main() {
    vector<long long> A = {2, 3, 5, 7, 13, 12};

    cout << plusMult(A) << endl;

    return 0;
}
