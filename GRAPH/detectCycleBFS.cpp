#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool detectCycle(int start,vector<vector<int>> &adj,vector<int> &visited){
        queue<pair<int,int>> q;
        visited[start] = 1;
        q.push({start,-1});
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            int size = adj[node].size();
            for(int i = 0;i<size;i++){
                int neighbour = adj[node][i];
                if(!visited[neighbour]){
                    visited[neighbour] = 1;
                    q.push({neighbour,node});
                }
                else{
                    if(parent!=neighbour){
                        return true;
                    }
                }
            }
            q.pop();
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        vector<int> visited(V,0);
        int E = edges.size();
        for(int i = 0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 0;i<V;i++){
            if(!visited[i]){
                if(detectCycle(i,adj,visited)){
                    return true;
                }
            }
        }
        return false;
        
    }
};