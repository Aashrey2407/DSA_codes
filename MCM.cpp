#include <bits/stdc++.h>
using namespace std;
int MCM(vector<int> &arr,int i,int j,vector<vector<int>> &dp){
        if(i>=j){
            return 0;
        }
        int min = INT_MAX;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(int k = i;k<=j-1;k++){
            int tempAns = MCM(arr,i,k,dp) + MCM(arr,k+1,j,dp) + arr[i-1]*arr[k]*arr[j];
            if(tempAns<min){
                min = tempAns;
            }
        }
        return dp[i][j] = min;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return MCM(arr,1,n-1,dp);
    }