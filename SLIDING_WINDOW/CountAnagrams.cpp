#include <bits/stdc++.h>
using namespace std;
int search(string &pat, string &txt) {
        // code here
        int n = txt.size();
        int k = pat.size();
        map<char,int> mpp;
        for(int i = 0;i<k;i++){
            mpp[pat[i]]++;
        }
        map<char,int> curmpp;
        int count = 0;
        int start = 0;
        int end = 0;
        while(end<n){
            curmpp[txt[end]]++;
            if(end-start+1==k){
                if(curmpp==mpp){
                    count++;
                }
                curmpp[txt[start]]--;
                if(curmpp[txt[start]]==0){
                    curmpp.erase(curmpp.find(txt[start]));
                }
                start++;
            }
            end++;
        }
        return count;
    }