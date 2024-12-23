#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string line;
    const regex pattern("mul\\([0-9]+,[0-9]+\\)");
    int ans = 0;
    while (getline(cin, line)) {
        const auto match_begin = sregex_iterator(line.begin(), line.end(), pattern);
        const auto match_end = sregex_iterator();
        for (auto it = match_begin; it != match_end; ++it) {
            int x, y;
            sscanf(it->str().c_str(), "mul(%d,%d)", &x, &y);
            ans += x * y;
        }
    }
    cout << ans << '\n';
    return 0;
}
