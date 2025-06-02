#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int columns = heights[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> dist(rows,vector<int> (columns,1e9));
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        while(!pq.empty()){
            int curRow = pq.top().second.first;
            int curCol = pq.top().second.second;
            int distance = pq.top().first;
            pq.pop();
            if(curRow == rows-1 && curCol == columns-1){
                return dist[curRow][curCol];
            }
            vector<int> delrow = {-1,0,1,0};
            vector<int> delcol = {0,1,0,-1};
            for(int i = 0;i<4;i++){
                int nRow = curRow + delrow[i];
                int nCol = curCol + delcol[i];
                if(nRow<rows && nRow>=0 && nCol<columns && nCol>=0 && max(abs(heights[nRow][nCol]-heights[curRow][curCol]),dist[curRow][curCol])<dist[nRow][nCol]){
                    dist[nRow][nCol] = max(abs(heights[nRow][nCol]-heights[curRow][curCol]),dist[curRow][curCol]);
                    pq.push({dist[nRow][nCol],{nRow,nCol}});
                }
            }
        }
        return -1;
    }
};