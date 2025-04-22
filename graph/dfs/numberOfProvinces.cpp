#include <bits/stdc++.h>
using namespace std;

class Solution {
    private:
        void bfs(int node, vector<vector<int>>& adj, vector<int>& vis){
            queue<int> que;
            que.push(node);
            vis[node] = 1;
    
            while(!que.empty()){
                int top = que.front();
                que.pop();
                for(auto &it: adj[top]){
                    if(!vis[it]){
                        que.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
        void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
            vis[node] = 1;
            for(auto & it: adj[node]){
                if(!vis[it]){
                    dfs(it,adj,vis);
                }
            }
        }
    public:
        int findCircleNum(vector<vector<int>>& isConnected) {
            // simply do bfs or dfs and count it
            int n = isConnected.size();
            vector<vector<int>> adj(n + 1);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(isConnected[i][j] == 1 && i != j){
                        adj[i].push_back(j);
                        adj[j].push_back(i);
                    }
                }
            }
            vector<int> visited(n + 1,false);
            int count = 0;
    
            for(int i = 0; i< n; i++){
                if(!visited[i]){
                    dfs(i,adj,visited);
                    count++;
                }
            }
            return count;
        }
    };