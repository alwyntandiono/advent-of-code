#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<int> A, B;
    for (int a, b; cin >> a >> b; ) {
        A.emplace_back(a);
        B.emplace_back(b);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    long long ans = 0;
    for (size_t i = 0; i < A.size(); ++i) {
        ans += abs(A[i] - B[i]);
    }
    cout << ans << '\n';
    return 0;
}
