/**
 * Created : 2024.08.02 10:11:27
 * Author: raj
 */
#include <bits/stdc++.h>

#define endl '\n'
using std::cout;
using std::cin;
using std::vector;
using std::max;
using ll = long long;

int dfs(vector<vector<int>> & v, vector<vector<int>>& memo, int i , int j) {
    static const vector<int> directions = {0, 1, 0, -1, 0};
    if (memo[i][j] != -1) return memo[i][j];
    int n = v.size();
    int m = v[0].size();
    int maxLength = 1;
    for (int d = 0; d < 4; d++) {
        int x = i + directions[d];
        int y = j + directions[d + 1];
        if (x >= 0 && x < n && y >= 0 && y < m && v[x][y] > v[i][j]) {
            maxLength = max(maxLength, 1 + dfs(v, memo, x, y));
        }
    }
    memo[i][j] = maxLength;
    return maxLength;
}

int longestIncreasingPath(vector<vector<int>> & v) {
    if (v.empty()) return 0;
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> memo(n, vector<int>(m, -1));
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans = max(ans, dfs(v, memo, i, j));
        }
    }
    return ans;
}

int main() {
    // Longest Increasing Path in a Matrix
    // Leetcode 329
    int n , m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    int ans = longestIncreasingPath(v);
    cout << ans << endl;

}
// tc 0(n * m)
// sc 0(n * m)
