/**
 * Created : 2024.08.02 09:50:09
 * Author: raj
 */
#include <bits/stdc++.h>

#define endl '\n'
using std::cout;
using std::cin;
using std::vector;
using ll = long long;

void dfs(vector<vector<int>> & v, int i , int j) {
    // counter
    int n = v.size();
    int m = v[0].size();
    if (i < 0 || j < 0 || i >= n || j >= m || v[i][j] == 0) return;
    v[i][j] = 0;
    dfs(v, i + 1, j);
    dfs(v, i - 1, j);
    dfs(v, i , j + 1);
    dfs(v, i , j - 1);
}

int numOfIslands(vector<vector<int>> & v) {
    if (v.empty()) return 0;
    int n = v.size();
    int m = v[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (v[i][j] == 1) {
                ans++;
                dfs(v, i, j);
            }
        }
    }
    return ans;
}

int main() {
    // Number Of Islands
    // Leetcode 200
    int n , m; cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }
    int ans = numOfIslands(v);
    cout << ans << endl;

}
// tc 0(n * m)
// sc 0(n * m)
