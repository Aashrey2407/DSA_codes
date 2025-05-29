#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int farthest = 0;
        int currentEnd = 0;
        int jumps = 0;
        int n = nums.size();
        for(int i = 0;i<n-1;i++){
            farthest = max(farthest,i+nums[i]);
            if(i==currentEnd){
                jumps++;
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};