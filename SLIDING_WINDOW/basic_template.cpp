#include <bits/stdc++.h>
using namespace std;
int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int start = 0;
        int end = 0;
        int sum = 0;
        int maxSum = 0;
        while(end<n){
            sum+=arr[end];
            if(end-start+1==k){
                maxSum = max(maxSum,sum);
                sum-=arr[start];
                start++;
            }
            end++;
        }
        return maxSum;
    }