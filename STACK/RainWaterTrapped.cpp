#include <bits/stdc++.h>
using namespace std;
//This question doesn't need stack, but i placed it in this folder because it looks like it needs stack but in fact it doesn't
vector<int> maxToTheLeft(vector<int> &heights){
        int maxLeft = 0;
        int n = heights.size();
        vector<int> answer(n);
        for(int i = 0;i<n;i++){
            answer[i] = maxLeft;
            maxLeft = max(maxLeft,heights[i]);
        }
        return answer;
    }
    vector<int> maxToTheRight(vector<int> &heights){
        int maxRight = 0;
        int n = heights.size();
        vector<int> answer(n);
        for(int i = n-1;i>=0;i--){
            answer[i] = maxRight;
            maxRight = max(maxRight,heights[i]);
        }
        return answer;
    }
    int trap(vector<int>& height) {
        vector<int> leftArray = maxToTheLeft(height);
        vector<int> rightArray = maxToTheRight(height);
        int n = height.size();
        int maxWaterTrapped = 0;
        for(int i = 0;i<n;i++){
            maxWaterTrapped+= max(0,min(leftArray[i],rightArray[i])-height[i]);
        }
        return maxWaterTrapped;
    }