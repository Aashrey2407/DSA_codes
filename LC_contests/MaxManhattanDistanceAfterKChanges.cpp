#include <bits/stdc++.h>
using namespace std;
int getMapping(char c){
        if(c=='N')return 0;
        if(c=='S')return 1;
        if(c=='E')return 2;
        if(c=='W')return 3;
        return -1;
    }

    int getMax(vector<int> &v,int k){
        int northCount = v[0];
        int southCount = v[1];
        int eastCount = v[2];
        int westCount = v[3];

        //Lets resolve the north-south direction
        int min1 = min(northCount,southCount);
        int max1 = max(northCount,southCount);
        int numCorrections = min(min1,k);

        //update the new max and min values
        max1+=numCorrections;
        min1-=numCorrections;
        int ans1 = max1-min1;
        //update the value of k
        k = max(k-numCorrections,0);
        
        //Lets resolve the east-west direction
        int min2 = min(eastCount,westCount);
        int max2 = max(eastCount,westCount);
        numCorrections = min(min2,k);

        //update the new max and min values
        max2+=numCorrections;
        min2-=numCorrections;

        int ans2 = max2-min2;
        
        return ans1+ans2;
    }
    int maxDistance(string s, int k) {
        vector<int> v(4,0);
        int n = s.size();
        int ans = 0;
        for(int i = 0;i<n;i++){
            v[getMapping(s[i])]++;
            int ans = max(ans,getMax(v,k));
        }
        return ans;
    }