#include <bits/stdc++.h>
using namespace std;
int longestKSubstr(string &s, int k) {
        // your code here
        int n = s.size();
        int start = 0;
        int end = 0;
        int maxLength = 0;
        map<char,int> mpp;
        while(end<n){
            mpp[s[end]]++;
            if(mpp.size()==k){
                maxLength = max(maxLength,end-start+1);
            }
            else if(mpp.size()>k){
                mpp[s[start]]--;
                if(mpp[s[start]]==0){
                    mpp.erase(mpp.find(s[start]));
                }
                start++;
            }
            end++;
        }
        if(maxLength==0){
            return -1;
        }
        return maxLength;
    }