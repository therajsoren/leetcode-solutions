// https://www.spoj.com/problems/ALIEN/

#include <bits/stdc++.h>

#define endl '\n'
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

void solve() {
    int At, Bt; cin >> At >> Bt;
    vector<int> v(At);
    rep(i, At) cin >> v[i];
    
    int currSum = 0;
    int maxSum = 0;
    int maxCnt = 0;
    int i = 0;
    
    for (int j = 0; j < At; j++) {
        currSum += v[j];
        
        while (currSum > Bt && i <= j) {
            currSum -= v[i];
            i++;
        }
        
        if (j - i + 1 > maxCnt) {
            maxCnt = j - i + 1;
            maxSum = currSum;
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