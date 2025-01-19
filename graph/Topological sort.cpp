#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/problems/topological-sort/1

class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    void DFS(vector<vector<int>> & adj, int u, vector<bool> &visited,stack<int> & st){
        visited[u] = true;
        
        // expolre u 
        for(int & v : adj[u]){
            if(!visited[v]){
                DFS(adj,v,visited,st);
            }
        }
        // backracking ke samay push u ko stack me
        st.push(u);
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<bool> visited(v,false);
        stack<int> st;
        for(int i = 0; i < v; i++){
            if(!visited[i]){
                DFS(adj,i,visited,st);
            }
        }
        vector<int> result;
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        return result;
    }
};
