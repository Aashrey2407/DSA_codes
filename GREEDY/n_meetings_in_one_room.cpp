#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int maxTime = 0;
        int meetings = 0;
        int minTime = INT32_MAX;
        int n = start.size();
        vector<pair<int,int>> pairTimes;
        for(int i = 0;i<n;i++){
            pairTimes.push_back({end[i],start[i]});
        }
        sort(pairTimes.begin(),pairTimes.end());
        for(int i = 0;i<n;i++){
            if(pairTimes[i].first<minTime || pairTimes[i].second>maxTime){
                meetings++;
                maxTime = max(maxTime,pairTimes[i].first);
                minTime = min(minTime,pairTimes[i].second);
            }
        }
        return meetings;
    }
};