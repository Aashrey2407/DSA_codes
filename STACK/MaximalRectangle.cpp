#include <bits/stdc++.h>
using namespace std;
vector<int> nearestSmallerToLeft(vector<int> &heights){
        int n = heights.size();
        stack<pair<int,int>> s;
        vector<int> answer(n);
        for(int i = 0;i<n;i++){
        while(s.size()){
            int topElement = s.top().first;
            int topElementIndex = s.top().second;
            if(topElement<heights[i]){
                answer[i] = (i - topElementIndex)*heights[i];
                break;
            }
            else{
                s.pop();
            }
        }
        if(s.empty()){
            answer[i] = (i+1)*heights[i];
        }
            s.push({heights[i],i});
        }
        return answer;
    }
    vector<int> nearestSmallerToRight(vector<int> &heights){
        int n = heights.size();
        stack<pair<int,int>> s;
        vector<int> answer(n);
        for(int i = n-1;i>=0;i--){
        while(s.size()){
            int topElement = s.top().first;
            int topElementIndex = s.top().second;
            if(topElement<heights[i]){
                answer[i] = (topElementIndex - i)*heights[i];
                break;
            }
            else{
                s.pop();
            }
        }
        if(s.empty()){
            answer[i] = (n-i)*heights[i];
        }
            s.push({heights[i],i});
        }
        return answer;
    }
    int maximumAreaOfRectangle(vector<int> &heights){
        int maxArea = 0;
        vector<int> leftArray = nearestSmallerToLeft(heights);
        vector<int> rightArray = nearestSmallerToRight(heights);
        int n = heights.size();
        for(int i = 0;i<n;i++){
            maxArea = max(maxArea,leftArray[i]+rightArray[i]-heights[i]);
        }
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heightStages(m,0);
        int maxArea = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                heightStages[j] = heightStages[j] + (matrix[i][j]-'0');
                if(matrix[i][j]=='0'){
                    heightStages[j] = 0;
                }
            }
            maxArea = max(maxArea,maximumAreaOfRectangle(heightStages));
        }
        return maxArea;
    }