#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int start = 0;
        int end = 0;
        int count = 0;
        map<char,int> mpp;
        int maxLength = 0;
        while(end<n){
            mpp[s[end]]++;
            count++;
            if(mpp.size()==count){
                maxLength = max(maxLength,end-start+1);
            }
            else{
                while(mpp.size()<count){
                    mpp[s[start]]--;
                    count--;
                    if(mpp[s[start]]==0){
                        mpp.erase(s[start]);
                    }
                    start++;
                }
            }
            end++;
        }
        return maxLength;
    }