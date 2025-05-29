//merge all overlapping intervals to get a list of non overlapping intervals
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> answer;
        answer.push_back({intervals[0][0],intervals[0][1]});
        for(int i = 1;i<n;i++){
            if(intervals[i][0]<=answer.back()[1]){
                answer.back()[1] = max(answer.back()[1],intervals[i][1]);
            }
            else{
                answer.push_back(intervals[i]);
            }
        }
        return answer;
    }
};