#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool dfs(int node,vector<vector<int>> &adj,vector<int> &path,vector<int> &visited){
        visited[node] = 1;
        path[node] = 1;
        int nSize = adj[node].size();
        for(int i = 0;i<nSize;i++){
            int neighbour = adj[node][i];
            if(!visited[neighbour]){
                if(dfs(neighbour,adj,path,visited)){
                    return true;
                }
            }
            else if(path[neighbour]){
                return true;
            }
        }
        path[node] = 0;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        int E = edges.size();
        for(int i = 0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        vector<int> visited(V,0);
        vector<int> path(V,0);
        for(int i = 0;i<V;i++){
            if(!visited[i]){
                if(dfs(i,adj,path,visited)){
                    return true;
                }
            }
        }
        return false;
    }
};