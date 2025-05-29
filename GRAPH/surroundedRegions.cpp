#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int row,int col,vector<vector<char>> &board,vector<vector<int>> &visited){
        visited[row][col] = 1;
        vector<int> delrow = {-1,0,1,0};
        vector<int> delcol = {0,1,0,-1};
        int rows = board.size();
        int columns = board[0].size();
        for(int i = 0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow<rows && nrow>=0 && ncol<columns && ncol>=0 && !visited[nrow][ncol] && board[nrow][ncol]=='O'){
                dfs(nrow,ncol,board,visited);
            }
        }
        return;
    }
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        int columns = board[0].size();
        vector<vector<int>> visited(rows,vector<int> (columns,0));
        for(int i = 0;i<columns;i++){
            if(board[0][i]=='O'&&!visited[0][i]){
                dfs(0,i,board,visited);
            }
            if(board[rows-1][i]=='O'&&!visited[rows-1][i]){
                dfs(rows-1,i,board,visited);
            }
        }
        for(int i = 0;i<rows;i++){
            if(board[i][0]=='O' && !visited[i][0]){
                dfs(i,0,board,visited);
            }
            if(board[i][columns-1]=='O' && !visited[i][columns-1]){
                dfs(i,columns-1,board,visited);
            }
        }
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<columns;j++){
                if(!visited[i][j]&&board[i][j]=='O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};