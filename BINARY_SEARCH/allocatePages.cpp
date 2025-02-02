#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<int> &arr,int k,int maxPages){
        int n = arr.size();
        int sum = 0;
        int students = 1;
        for(int i = 0;i<n;i++){
            sum+=arr[i];
            if(sum>maxPages){
                students++;
                sum = arr[i];
            }
        }
        if(students>k){
            return false;
        }
        return true;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        
        int n = arr.size();
        if(k>n){
            return -1;
        }
        int start,end;
        int maxi = 0;
        int sum = 0;
        for(int i = 0;i<n;i++){
            maxi = max(maxi,arr[i]);
            sum+=arr[i];
        }
        start = maxi;
        end = sum;
        int answer = -1;
        while(start<=end){
            int mid = (start+end)/2;
            if(isValid(arr,k,mid)){
                answer = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return answer;
    }