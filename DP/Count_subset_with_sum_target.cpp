#include <bits/stdc++.h>
using namespace std;
int countSubsets(vector<int> &arr, int n,int target,vector<vector<int>> &dp){
        if(n==0 && target==0){
            return 1;
        }
        if(n==0){
            return 0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        if(arr[n-1]<=target){
            return dp[n][target] = countSubsets(arr,n-1,target-arr[n-1],dp) + countSubsets(arr,n-1,target,dp);
        }
        return dp[n][target] = countSubsets(arr,n-1,target,dp);
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        return countSubsets(arr,n,target,dp);
    }