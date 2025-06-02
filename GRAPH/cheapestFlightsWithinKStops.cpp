#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        int E = flights.size();
        for(int i = 0;i<E;i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int cost = flights[i][2];
            adj[u].push_back({v,cost});
        }
        queue<pair<int,pair<int,int>>> q;
        vector<int> dist(n,1e9);
        q.push({0,{-1,src}});
        dist[src] = 0;
        while(!q.empty()){
            int distance = q.front().first;
            int stops = q.front().second.first;
            int node = q.front().second.second;
            q.pop();
            if(stops==k){
                continue;
            }
            int nSize = adj[node].size();
            for(int i = 0;i<nSize;i++){
                int neighbour = adj[node][i].first;
                int weight = adj[node][i].second;
                if(distance+weight<dist[neighbour]){
                    dist[neighbour] = distance+weight;
                    q.push({dist[neighbour],{stops+1,neighbour}});
                }
            }
        }
        return dist[dst]==1e9?-1:dist[dst];
    }
};