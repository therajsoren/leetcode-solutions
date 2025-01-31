// https://www.spoj.com/problems/CODFURY/
#include <bits/stdc++.h>

#define endl '\n'
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

void solve() {
    int n , m; cin >> n >> m;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    int maxSum = 0;
    int maxCnt = 0;
    int currSum = 0;
    int i = 0;
    for (int j = 0; j < n; j++) {
        currSum += v[j];
        while (currSum > m) {
            currSum -= v[i];
            i++;
        }
        if (j - i + 1 > maxCnt) {
            maxCnt = max(maxCnt, j - i + 1);
            maxSum = max(maxSum, currSum);
        } else if (j - i + 1 == maxCnt) {
            maxSum = min(maxSum, currSum);
        }
    }
    cout << maxSum << " " << maxCnt << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tt = 1;
    cin >> tt;
    while (tt--) {
        solve();
    }
}
