#include <bits/stdc++.h>
using namespace std;
int numWays(string &s,int i,int j,vector<vector<vector<int>>> &dp,bool isTrue){
        int MOD = 1003;
        if(i==j){
            if(s[i]=='T'){
                dp[i][j][0] = 1;
                dp[i][j][1] = 0;
            }
            else{
                dp[i][j][1] = 1;
                dp[i][j][0] = 0;
            }
            
        }
        if(isTrue && dp[i][j][0]!=-1){
            return dp[i][j][0];
        }
        if(!isTrue && dp[i][j][1]!=-1){
            return dp[i][j][1];
        }
        int tempTrue = 0;
        int tempFalse = 0;
        for(int k = i+1;k<=j-1;k+=2){
            int n = numWays(s,i,k-1,dp,true)%MOD;
            int x = numWays(s,i,k-1,dp,false)%MOD;
            int m = numWays(s,k+1,j,dp,true)%MOD;
            int y = numWays(s,k+1,j,dp,false)%MOD;
            if(s[k]=='|'){
                tempTrue+=(n*y+x*m+n*m)%MOD;
                tempFalse+=(x*y)%MOD;
            }
            else if(s[k]=='&'){
                tempTrue+=(n*m)%MOD;
                tempFalse+=(n*y+x*m+x*y)%MOD;
            }
            else if(s[k]=='^'){
                tempTrue+=(n*y+x*m)%MOD;
                tempFalse+=(n*m+x*y)%MOD;
            }
        }
        dp[i][j][0] = tempTrue;
        dp[i][j][1] = tempFalse;
        if(isTrue){
        return dp[i][j][0]%MOD;
        }
        return dp[i][j][1]%MOD;
    }
    int countWays(int n, string s){
        // code here
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>> (n+1,vector<int> (2,-1)));
        return numWays(s,0,n-1,dp,true);
        
    }