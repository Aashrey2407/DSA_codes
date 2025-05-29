#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void bfs(vector<vector<int>> &mat,vector<vector<int>> &distance,vector<vector<int>> &visited){
        queue<pair<int,int>> q;
        int rows = mat.size();
        int columns = mat[0].size();
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<columns;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    distance[i][j] = 0;
                }
            }
        }
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0;i<size;i++){
                int row = q.front().first;
                int col = q.front().second;
                if(mat[row][col]==1){
                    distance[row][col] = level;
                }
                vector<int> rowss = {-1,0,1,0};
                vector<int> cols = {0,1,0,-1};
                for(int i = 0;i<4;i++){
                    int nrow = row + rowss[i];
                    int ncol = col + cols[i];
                    if(nrow<rows && nrow>=0 && ncol<columns && ncol>=0 && !visited[nrow][ncol] && mat[nrow][ncol]==1){
                        visited[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
                q.pop();
            }
            level++;
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int columns = mat[0].size();
        vector<vector<int>> distance(rows,vector<int> (columns,INT32_MAX));
        vector<vector<int>> visited(rows,vector<int> (columns,0));
        bfs(mat,distance,visited);
        return distance;
    }
};