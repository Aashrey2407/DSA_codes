//the link to the question is: https://www.interviewbit.com/problems/sliding-window-maximum/
#include <bits/stdc++.h>
using namespace std;
vector<int> slidingMaximum(const vector<int> &A, int B) {
    int n = A.size();
    int start = 0;
    int end = 0;
    vector<int> answer;
    priority_queue<pair<int,int>> maxHeap;
    map<pair<int,int>,int> mpp;
    while(end<n){
        maxHeap.push({A[end],end});
        if(end-start+1==B){
            pair<int,int> topElement = maxHeap.top();
            while(!maxHeap.empty() && mpp.find(maxHeap.top())!=mpp.end()){
                maxHeap.pop();
            }
            answer.push_back(maxHeap.top().first);
            if(maxHeap.top().first==A[start] && maxHeap.top().second==start){
                maxHeap.pop();
            }
            else{
                mpp[{A[start],start}]++;
            }
            start++;
        }
        end++;
    }
    return answer;
}

//alternate approach, can also use max and second max in every window, if max is being removed from window, make second max equal to max