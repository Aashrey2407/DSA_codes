#include <bits/stdc++.h>
using namespace std;
int maxValue(vector<int> &price,vector<int> &lengths,int n,int length,vector<vector<int>> &dp){
        if(length==0 || n==0){
            return 0;
        }
        if(dp[n][length]!=-1){
            return dp[n][length];
        }
        if(lengths[n-1]<=length){
            return dp[n][length] = max(maxValue(price,lengths,n,length-lengths[n-1],dp)+price[n-1],maxValue(price,lengths,n-1,length,dp));
        }
        return dp[n][length] = maxValue(price,lengths,n-1,length,dp);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        vector<int> lengths(n);
        for(int i = 0;i<n;i++){
            lengths[i] = i+1;
        }
        return maxValue(price,lengths,n,n,dp);
    }