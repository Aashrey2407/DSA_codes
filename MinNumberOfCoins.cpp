#include <bits/stdc++.h>
using namespace std;
int minNumberOfCoins(vector<int> &coins,int n,int sum,vector<vector<int>> &dp){
        if(sum==0){
            return 0;
        }
        if(n==0){
            return INT_MAX-1;
        }
        if(dp[n][sum]!=-1){
            return dp[n][sum];
        }
        if(coins[n-1]<=sum){
            return min(1+minNumberOfCoins(coins,n,sum-coins[n-1],dp),minNumberOfCoins(coins,n-1,sum,dp));
        }
        return minNumberOfCoins(coins,n-1,sum,dp);
    }
    int minCoins(vector<int> &coins, int sum) {
        // Your code goes here
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        int answer = minNumberOfCoins(coins,n,sum,dp);
        if(answer==INT_MAX){
            return -1;
        }
        return minNumberOfCoins(coins,n,sum,dp);
    }