#include <bits/stdc++.h>
using namespace std;
int findTarget(vector<int>& arr, int target) {
        // Your code here
        int n = arr.size();
        int start = 0;
        int end = n-1;
        while(start<=end){
            int mid = (start+end)/2;
            if(arr[mid]==target){
                return mid;
            }
            int left = (mid+n-1)%n;
            int right = (mid+1)%n;
            if(arr[mid]<target){
                if(arr[left]==target){
                    return left;
                }
                else{
                    start = mid+1;
                }
            }
            else if(arr[mid]>target){
                if(arr[right]==target){
                    return right;
                }
                else{
                    end = mid-1;
                }
            }
        }
        return -1;
    }