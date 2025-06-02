#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  vector<int> bfs(vector<vector<int>> &adj,vector<int> &indegree){
        int N = adj.size();
        queue<int> q;
        vector<int> topoSort;
        for(int i = 0;i<N;i++){
            if(indegree[i]==0){
                q.push(i);
                topoSort.push_back(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            for(int i : adj[node]){
                indegree[i]--;
                if(indegree[i]==0){
                    q.push(i);
                    topoSort.push_back(i);
                }
            }
            q.pop();
        }
        return topoSort;
    }
    string findOrder(vector<string> &words) {
        // code here
        unordered_set<char> unique_chars;
        for (const string &word : words) {
            for (char c : word) {
                unique_chars.insert(c);
            }
        }
        int N = words.size();
        int K = unique_chars.size();
        map<char,int> char_to_int;
        vector<char> int_to_char;
        int i = 0;
        for(char c : unique_chars){
            char_to_int[c] = i++;
            int_to_char.push_back(c);
        }
        vector<vector<int>> adj(K);
        vector<int> indegree(K,0);
        for(int i = 0; i < N - 1; i++){
            string &w1 = words[i];
            string &w2 = words[i+1];
            int size1 = w1.size();
            int size2 = w2.size();
        
            if (size1 > size2 && w1.substr(0, size2) == w2) {
                return "";
            }
        
            for(int j = 0; j < min(size1, size2); j++){
                if(w1[j] != w2[j]){
                    int idx1 = char_to_int[w1[j]];
                    int idx2 = char_to_int[w2[j]];
                    adj[idx1].push_back(idx2);
                    indegree[idx2]++;
                    break;
                }
            }
        }
        string answer;
        vector<int> topoSort = bfs(adj,indegree);
        if(topoSort.size()<K){
            return "";
        }
        for(int i = 0;i<topoSort.size();i++){
            int idx = topoSort[i];
            char c = int_to_char[idx];
            answer+=c;
        }
        return answer;
	}
};