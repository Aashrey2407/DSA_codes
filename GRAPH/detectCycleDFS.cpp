#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool detectCycle(int node,int parent,vector<vector<int>> &adj,vector<int> &visited){
        visited[node] = 1;
        int size = adj[node].size();
        for(int i = 0;i<size;i++){
            int neighbour = adj[node][i];
            if(!visited[neighbour]){
                if(detectCycle(neighbour,node,adj,visited)){
                    return true;
                }
            }
            else{
                if(parent!=neighbour){
                    return true;
                }
            }
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
                if(detectCycle(i,-1,adj,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};