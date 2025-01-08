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
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n = arr.size();
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum+=arr[i];
        }
        if((sum-d)%2==1 || (sum-d)<0){
            return 0;
        }
        int target = (sum - d)/2;
        vector<vector<int>> dp(n+1,vector<int> (target+1,-1));
        return countSubsets(arr,n,target,dp);
    }