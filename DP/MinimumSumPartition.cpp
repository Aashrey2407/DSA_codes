#include <bits/stdc++.h>
using namespace std;
void subsetSum(vector<int> &arr,int n, int sum,vector<vector<int>> &dp){
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=sum;j++){
                if(j==0){
                    dp[i][j] = 1;
                }
                else if(i==0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=sum;j++){
                if(arr[i-1]<=j){
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    int minDifference(vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=arr[i];
        }
        vector<vector<int>> dp(n+1,vector<int> (sum+1,-1));
        subsetSum(arr,n,sum,dp);
        int largestSum = 0;
        for(int i = 0;i<=sum/2;i++){
            if(dp[n][i]==1){
                largestSum = i;
            }
        }
        int minDiff = sum - 2*largestSum;
        return minDiff;
    }