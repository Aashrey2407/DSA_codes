#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkValidString(string s) {
        int minCount = 0;
        int maxCount = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(s[i]=='('){
                minCount++;
                maxCount++;
            }
            else if(s[i]==')'){
                minCount--;
                maxCount--;
            }
            else{
                minCount--;
                maxCount++;
            }
            if(minCount<0){
                minCount=0;
            }
            if(maxCount<0){
                return false;
            }
        }
        return minCount==0;
    }
};