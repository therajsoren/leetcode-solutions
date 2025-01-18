#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void BFS(vector<vector<int>> &adj,int u, vector<bool> &visited, vector<int> &result){
        queue<int> que;
        
        que.push(u);
        visited[u] = true;
        result.push_back(u);
        
        while(!que.empty()){
            int u = que.front();
            que.pop();
            
            // result.push_back(v);
            for(int & v : adj[u]){
                if(!visited[v]){
                    que.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }
        }
    }
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> result;
        vector<bool> visited(V,false);
        BFS(adj,0,visited,result);
        return result;
    }
};
