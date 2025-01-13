#include <bits/stdc++.h>
using namespace std;
int minNumberOfCoins(vector<int> &coins,int n,int sum,vector<vector<int>> &dp){
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=sum;j++){
                if(j==0){
                    dp[i][j] = 0;
                }
                else if(i==0){
                    dp[i][j] = INT_MAX -1;
                }
            }
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=sum;j++){
                if(coins[i-1]<=j && coins[i-1]!=0){
                    dp[i][j] =  min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    int minCoins(vector<int> &coins, int sum) {
        // Your code goes here
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        int answer = minNumberOfCoins(coins,n,sum,dp);
        if(answer==INT_MAX-1){
            return -1;
        }
        return answer;
    }