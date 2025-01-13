#include <bits/stdc++.h>
using namespace std;
int LCS(string str1,string str2,int n, int m,vector<vector<int>> &dp){
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=m;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }
            }
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=m;j++){
                if(str1[i-1]==str2[j-1] && i!=j){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    int LongestRepeatingSubsequence(string &s) {
        // Code here
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        return LCS(s,s,n,n,dp);
    }