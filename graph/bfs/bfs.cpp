#include <bits/stdc++.h>

using namespace std;

vector<int> ans;

void bfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int> & ans) {
	queue<int> que;
	que.push(node);
	vis[1] = 1; // 1based for 0 based replace vis[1] with vis[0]
	ans.push_back(node);
	while(!que.empty()) {
		int top = que.front();
		que.pop();

		for(auto & it : adj[top]) {
			if(!vis[it]) {
				que.push(it);
				ans.push_back(it);
				vis[it] = 1;
			}
		}
	}

}

int main() {
	int n,m;cin>>n>>m;

	vector<vector<int>> adj(n + 1);
	for(int i = 0; i < m; i++) {
		int u,v;
		cin>>u>>v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// bfs

	// isme level wise traverse krte hai

	vector<int> visited(n,false);

	bfs(1,adj,visited,ans); // 1based for 0 based replace 1 with 0

	for(auto & it : ans) {
		cout << it << ' ';
	}
}