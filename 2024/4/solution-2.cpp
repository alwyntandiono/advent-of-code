#include <bits/stdc++.h>
using namespace std;

void grid_search(const vector<string>& grid, string_view pat, vector<vector<int>>& mark) {
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[0].size(); ++j) {
            size_t k = 0;
            while (i + k < grid.size() && j + k < grid[0].size() && k < pat.size() && grid[i + k][j + k] == pat[k]) {
                ++k;
            }
            if (k == pat.size()) {
                mark[i][j] |= 0x1;
            }
        }
    }
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[0].size(); ++j) {
            size_t k = 0;
            while (i >= k && j + k < grid[0].size() && k < pat.size() && grid[i - k][j + k] == pat[k]) {
                ++k;
            }
            if (k == pat.size()) {
                mark[i][j] |= 0x2;
            }
        }
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<string> grid;
    for (string s; getline(cin, s); ) {
        grid.emplace_back(s);
    }
    vector mark(grid.size(), vector(grid[0].size(), 0));
    grid_search(grid, "MAS", mark);
    grid_search(grid, "SAM", mark);
    int ans = 0;
    for (size_t i = 0; i + 2 < grid.size(); ++i) {
        for (size_t j = 0; j + 2 < grid[0].size(); ++j) {
            ans += (mark[i][j] & 0x1) == 0x1 && (mark[i + 2][j] & 0x2) == 0x2;
        }
    }
    cout << ans << '\n';
    return 0;
}
