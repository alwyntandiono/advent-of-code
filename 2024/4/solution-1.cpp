#include <bits/stdc++.h>
using namespace std;

int grid_search(const vector<string>& grid, string_view pat) {
    int occurenceCount = 0;
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[0].size(); ++j) {
            size_t k = 0;
            while (j + k < grid[0].size() && k < pat.size() && grid[i][j + k] == pat[k]) {
                ++k;
            }
            occurenceCount += k == pat.size();
        }
    }
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[0].size(); ++j) {
            size_t k = 0;
            while (i + k < grid.size() && k < pat.size() && grid[i + k][j] == pat[k]) {
                ++k;
            }
            occurenceCount += k == pat.size();
        }
    }
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[0].size(); ++j) {
            size_t k = 0;
            while (i + k < grid.size() && j + k < grid[0].size() && k < pat.size() && grid[i + k][j + k] == pat[k]) {
                ++k;
            }
            occurenceCount += k == pat.size();
        }
    }
    for (size_t i = 0; i < grid.size(); ++i) {
        for (size_t j = 0; j < grid[0].size(); ++j) {
            size_t k = 0;
            while (i >= k && j + k < grid[0].size() && k < pat.size() && grid[i - k][j + k] == pat[k]) {
                ++k;
            }
            occurenceCount += k == pat.size();
        }
    }
    return occurenceCount;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<string> grid;
    for (string s; getline(cin, s); ) {
        grid.emplace_back(s);
    }
    string pat = "XMAS";
    int ans = grid_search(grid, pat);
    reverse(pat.begin(), pat.end());
    ans += grid_search(grid, pat);
    cout << ans << '\n';
    return 0;
}
