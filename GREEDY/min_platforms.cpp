//The idea here is to find maximum overlap between intervals using sweep line idea(sorting + two pointers)
#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        vector<pair<int,int>> pairTimes;
        int n = arr.size();
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int i = 1;
        int j = 0;
        int minPlatforms = 1;
        int answer = 1;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                minPlatforms++;
                i++;
            }
            else{
                minPlatforms--;
                j++;
            }
            answer = max(minPlatforms,answer);
        }
        return answer;
    }
};
