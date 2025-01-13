#include <bits/stdc++.h>
using namespace std;
bool checkPalindrome(string &s,int start,int end){
        if(palindrome[start][end]!=-1){
            return palindrome[start][end];
        }
        while(start<=end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return palindrome[start][end] = true;
    }
    int palinPartition(string &s,int i,int j,vector<vector<int>> &dp,vector<vector<int>> palindrome){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(checkPalindrome(s,i,j,palindrome)){
            return 0;
        }
        int minCuts = INT_MAX;
        for(int k = i;k<=j-1;k++){
            int left,right;
            if(dp[i][k]!=-1){
                left = dp[i][k];
            }
            else{
                left = palinPartition(s,i,k,dp,palindrome);
            }
            if(dp[k+1][j]!=-1){
                right = dp[k+1][j];
            }
            else{
                right = palinPartition(s,k+1,j,dp,palindrome);
            }
            int tempAns = 1+left+right;
            if(tempAns<minCuts){
                minCuts = tempAns;
            }
        }
        return dp[i][j] = minCuts;
    }
    int palindromicPartition(string &s) {
        // code here
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
        vector<vector<int>> palindrome(n+1,vector<int> (n+1,-1));
        return palinPartition(s,0,n-1,dp,palindrome);
    }