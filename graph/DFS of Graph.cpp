#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/0

class Solution {
  public:
    void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<int> & result){
        if(visited[u] == true) return;
        visited[u] = true;
        result.push_back(u);
        for(int & v : adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited,result);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> result;
        vector<bool> visited(V,false);
        DFS(adj,0,visited,result);
        return result;
    }
};
