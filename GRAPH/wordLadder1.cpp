#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool adjWords(string s1,string s2){
        int size = s2.size();
        int count = 0;
        for(int i = 0;i<size;i++){
            if(s1[i]!=s2[i]){
                count++;
            }
        }
        return count==1;
    }
    int bfs(map<string,vector<string>> &adj,string beginWord,string endWord,map<string,int> &visited){
        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = 1;
        int level = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                string current = q.front();
                if(current==endWord){
                    return level;
                }
                int nSize = adj[current].size();
                for(int i = 0;i<nSize;i++){
                    string neighbour = adj[current][i];
                    if(!visited[neighbour]){
                    q.push(neighbour);
                    visited[neighbour] = 1;
                    }
                }
                q.pop();
            }
            level++;
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        map<string,vector<string>> adj;
        int size = wordList.size();
        map<string,int> visited;
        for(int i = 0;i<size;i++){
            int wordSize = wordList[i].size();
            if(adjWords(beginWord,wordList[i])){
                adj[beginWord].push_back(wordList[i]);
                adj[wordList[i]].push_back(beginWord);
            }
        }
        unordered_set<string> st(wordList.begin(),wordList.end());
        for(int i = 0;i<size;i++){
            int wordSize = wordList[i].size();
            string word = wordList[i];
            for(int j = 0;j<wordSize;j++){
                for(char c = 'a';c<='z';c++){
                    word[j] = c;
                    if(st.find(word)!=st.end()){
                        adj[wordList[i]].push_back(word);
                    }
                }
                word = wordList[i];
            }
        }
        return bfs(adj,beginWord,endWord,visited);
    }
};