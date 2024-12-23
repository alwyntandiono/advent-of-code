#include <bits/stdc++.h>
using namespace std;

bool is_safe(const vector<int>& report) {
    if (!is_sorted(report.begin(), report.end()) && !is_sorted(report.rbegin(), report.rend())) {
        return false;
    }
    for (size_t i = 1; i < report.size(); ++i) {
        const int diff = abs(report[i] - report[i - 1]);
        if (diff < 1 || diff > 3) {
            return false;
        }
    }
    return true;
}

bool is_tolerantly_safe(vector<int>& report) {
    if (is_safe(report)) {
        return true;
    }
    for (auto it = report.begin(); it != report.end(); ++it) {
        const int level = *it;
        report.erase(it);
        if (is_safe(report)) {
            return true;
        }
        report.emplace(it, level);
    }
    return false;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string line;
    int ans = 0;
    while (getline(cin, line)) {
        istringstream ss(line);
        int level;
        vector<int> report;
        while (ss >> level) {
            report.emplace_back(level);
        }
        ans += is_tolerantly_safe(report);
    }
    cout << ans << '\n';
    return 0;
}
