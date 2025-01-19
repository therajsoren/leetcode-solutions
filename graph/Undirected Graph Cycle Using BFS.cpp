#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycleBFS(vector<vector<int>> &adj, int u, vector<bool> & visited){
        queue<pair<int,int>> que;
        que.push({u,-1});
        visited[u] = true;
        while(!que.empty()){
            int source = que.front().first;
            int parent = que.front().second;
            
            que.pop();
            // explore u
            for(auto & v : adj[source]){
                if(!visited[v]){
                    que.push({v,source});
                    visited[v] = true;
                } else if(v != parent){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<bool> visited(v,false);
        for(int i = 0; i < v; i++){
            if(!visited[i] && isCycleBFS(adj,i,visited)){
                return true;
            }
        }
        return false;
    }
};
