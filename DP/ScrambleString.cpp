#include <bits/stdc++.h>
using namespace std;
bool checkScrambled(string s1,string s2,map<pair<string,string>,bool> &mpp){
        int n = s1.size();
        if(n==0){
            return true;
        }
        if(n==1){
            return s1[0]==s2[0];
        }
        if(mpp.find({s1,s2})!=mpp.end()){
            return mpp[{s1,s2}];
        }
        for(int i = 0;i<n-1;i++){
            if(checkScrambled(s1.substr(0,i+1),s2.substr(0,i+1),mpp)&&checkScrambled(s1.substr(i+1,n-i-1),s2.substr(i+1,n-i-1),mpp)){
                return mpp[{s1,s2}] = true;
            }
            if(checkScrambled(s1.substr(0,i+1),s2.substr(n-i-1,i+1),mpp)&&checkScrambled(s1.substr(i+1,n-i-1),s2.substr(0,n-i-1),mpp)){
                return mpp[{s1,s2}] = true;
            }
        }
        return mpp[{s1,s2}] = false;
    }
    bool isScramble(string s1, string s2) {
        int n = s1.size();
        map<pair<string,string>,bool> mpp;
        return checkScrambled(s1,s2,mpp);

    }