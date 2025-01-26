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
                    answer[i] = (topElementIndex-i)*heights[i];
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
    int largestRectangleArea(vector<int>& heights) {
        vector<int> leftArray = nearestSmallerToLeft(heights);
        vector<int> rightArray = nearestSmallerToRight(heights);
        int n = heights.size();
        int maxArea = 0;
        for(int i = 0;i<n;i++){
            maxArea = max(maxArea,leftArray[i]+rightArray[i]-heights[i]);
        }
        return maxArea;
    }