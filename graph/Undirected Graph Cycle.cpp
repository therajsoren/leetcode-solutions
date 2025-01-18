#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycleDFS(vector<vector<int>> & adj, int u, vector<bool> &visited,int parent){
        visited[u] = true;
        // explore u
        for(auto & v : adj[u]){
            if(v == parent) continue; // skip if v == parent
            if(isCycleDFS(adj,v,visited,u)){
                return true;
            }
            // agar visited hai to cycle form hu rah to return true;
            if(visited[v]) return true;
        }
        return false;
    }
    bool isCycle(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<bool> visited(v,false);
        for(int i = 0; i < v; i++){
            if(!visited[i] && isCycleDFS(adj,i,visited,-1)){  // taking -1 as parent
                return true;
            }
        }
        return false;
    }
};
