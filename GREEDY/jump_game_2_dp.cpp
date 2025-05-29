#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        memset(dp,INT32_MAX,sizeof(dp));
        dp[n-1] = 0;
        for(int i = n-2;i>=0;i--){
            int minJumps = INT32_MAX;
            for(int j = i+1;j<=i+nums[i] && j<n;j++){
                minJumps = min(minJumps,dp[j]);
            }
            if(minJumps<INT32_MAX){
                dp[i] = 1 + minJumps;
            }
            else{
                dp[i] = INT32_MAX;
            }
        }
        return dp[0];
    }
};