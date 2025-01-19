#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

class Solution {
  public:
     
    bool isCycleDFS(vector<vector<int>> &adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        
        
        for(int &v : adj[u]) {
            // if not visited, then we check for cylce in DFS
            if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion))
                return true;
            // agar visited rha hoga aur agar current recursion me visited hoga tu return true;
            else if(inRecursion[v] == true)
                return true;
        }
        
        inRecursion[u] = false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> adj) {
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);
        
        for(int i = 0; i < V; i++) {
            if(!visited[i] && isCycleDFS(adj, i, visited, inRecursion))
                return true;
        }
        return false;
    }
};
