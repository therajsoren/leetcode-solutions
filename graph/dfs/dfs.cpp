#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& ans){
    ans.push_back(node);
    vis[node] = 1;
    
    for(auto & it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, ans);
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < m; i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> visited(n,false);
    vector<int> ans;
    
    dfs(1,adj,visited,ans);
    
    for(auto & it: ans){
        cout << it << " ";
    }
}