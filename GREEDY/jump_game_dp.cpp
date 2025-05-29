#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int dp[n];
        memset(dp,0,sizeof(dp));
        dp[n-1] = 1;
        for(int i = n-2;i>=0;i--){
            bool possible = false;
            for(int j = i;j<=i+nums[i];j++){
                if(dp[j]==1){
                    dp[i] = 1;
                    possible = true;
                    break;
                }
            }
            if(!possible){
                dp[i] = 0;
            }
        }
        return dp[0];
    }
};