#include <bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        int n = nums.size();
        for(int i = 0;i<k;i++){
            minHeap.push(nums[i]);
        }
        for(int i = k;i<n;i++){
            int kMin = minHeap.top();
            minHeap.pop();
            if(nums[i]>kMin){
                minHeap.push(nums[i]);
            }
            else{
                minHeap.push(kMin);
            }
        }
        return minHeap.top();
    }