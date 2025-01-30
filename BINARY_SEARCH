#include <bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int firstOccurenceIndex = n;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]>=target){
                firstOccurenceIndex = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        start = 0;
        end = n-1;
        int lastOccurenceIndex = n;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]>target){
                lastOccurenceIndex = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        if(firstOccurenceIndex==lastOccurenceIndex){
            return {-1,-1};
        }
        return {firstOccurenceIndex,lastOccurenceIndex-1};
    }