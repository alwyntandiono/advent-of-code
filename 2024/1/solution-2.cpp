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
    for (size_t i = 0, l = 0, r = 0; i < A.size(); ++i) {
        while (r < B.size() && B[r] <= A[i]) {
            ++r;
        }
        while (l < r && B[l] < A[i]) {
            ++l;
        }
        ans += A[i] * (r - l);
    }
    cout << ans << '\n';
    return 0;
}
