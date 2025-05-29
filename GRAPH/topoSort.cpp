#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    void dfs(int node,vector<vector<int>> &adj,vector<int> &visited,stack<int> &st){
        visited[node] = 1;
        int nSize = adj[node].size();
        for(int i = 0;i<nSize;i++){
            int neighbour = adj[node][i];
            if(!visited[neighbour]){
            dfs(neighbour,adj,visited,st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        int E = edges.size();
        for(int i = 0;i<E;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        stack<int> st;
        vector<int> visited(V,0);
        for(int i = 0;i<V;i++){
            if(!visited[i]){
                dfs(i,adj,visited,st);
            }
        }
        vector<int> answer;
        while(!st.empty()){
            answer.push_back(st.top());
            st.pop();
        }
        return answer;
    }
};