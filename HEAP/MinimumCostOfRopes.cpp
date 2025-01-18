#include <bits/stdc++.h>
using namespace std;
 // Function to return the minimum cost of connecting the ropes.
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>> minHeap;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            minHeap.push(arr[i]);
        }
        if(n<2){
            return 0;
        }
        int answer = 0;
        while(minHeap.size()>1){
            int lowest = minHeap.top();
            minHeap.pop();
            int secondLowest = minHeap.top();
            minHeap.pop();
            answer+=lowest+secondLowest;
            minHeap.push(lowest + secondLowest);
        }
        return answer;
    }