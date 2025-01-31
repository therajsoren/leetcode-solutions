#include <bits/stdc++.h>

#define endl '\n'
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()

using namespace std;
using ll = long long;

void solve() {
    int n; cin >> n;
    vector<int> v(n);
    rep(i, n) cin >> v[i];
    int k; cin >> k;
    vector<int> res;
    deque<int> dq;
    for(int i = 0; i < n; i++){
        if(!dq.empty() && dq.front() == i - k){
            dq.pop_front();
        }
        while(!dq.empty() && v[dq.back()] < v[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= k - 1){
            res.push_back(v[dq.front()]);
        }
    }
    for (auto & it : res)  cout << it << " ";
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int tt = 1;
    // cin >> tt;
    while (tt--) {
        solve();
    }
}