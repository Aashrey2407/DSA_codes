//Here we can't use sliding window because in the question it was mentioned that negative values are also allowed in the array. If only positive values were there, we could've used sliding window approach.
//So we have to use hash map approach
#include <bits/stdc++.h>
using namespace std;
int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int sum = 0;
        map<int,int> prefixSum;
        int maxLength = 0;
        for(int i = 0;i<n;i++){
            sum+=arr[i];
            if(sum==k){
                maxLength = max(maxLength,i+1);
            }
            if(prefixSum.find(sum-k)!=prefixSum.end()){
                maxLength = max(maxLength,i-prefixSum[sum-k]);
            }
            if(prefixSum.find(sum)==prefixSum.end()){
                prefixSum[sum] = i;
            }
        }
        return maxLength;
    }