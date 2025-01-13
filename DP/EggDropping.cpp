#include <bits/stdc++.h>
using namespace std;
int minTurns(int n,int k,vector<vector<int>> &dp){
        if(n==0){
            return 0;
        }
        if(n==1 || k==0 || k==1){
            return k;
        }
        if(dp[n][k]!=-1){
            return dp[n][k];
        }
        int minimum = INT_MAX;
        for(int i = 1;i<=k;i++){
            int tempAns = 1 + max(minTurns(n-1,i-1,dp),minTurns(n,k-i,dp));
            minimum = min(tempAns,minimum);
        }
        return dp[n][k] = minimum;
    }
    int eggDrop(int n, int k) {
        // your code here
        vector<vector<int>> dp(n+1,vector<int> (k+1,-1));
        return minTurns(n,k,dp);
        
    }