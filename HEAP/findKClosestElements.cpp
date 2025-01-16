#include <bits/stdc++.h>
using namespace std;
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        map<int,int> mpp;
        int n = arr.size();
        for(int i = 0;i<n;i++){
            mpp[arr[i]] = abs(arr[i]-x);
        }
        
        auto cmp = [&mpp](int a, int b) {
        if (mpp[a] == mpp[b]) return a < b; 
        return mpp[a] < mpp[b];
        };

    
        priority_queue<int, vector<int>, decltype(cmp)> maxHeap(cmp);
        
        for(int i = 0;i<k;i++){
            maxHeap.push(arr[i]);
        }
        for(int i = k;i<n;i++){
            int topElement = maxHeap.top();
            maxHeap.pop();
            if(mpp[arr[i]]<mpp[topElement]){
                maxHeap.push(arr[i]);
            }
            else if(mpp[arr[i]]==mpp[topElement]&&arr[i]<topElement){
                maxHeap.push(arr[i]);
            }
            else{
                maxHeap.push(topElement);
            }
        }
        vector<int> answer(k);
        int index = k-1;
        while(maxHeap.size()){
            answer[index--] = maxHeap.top();
            maxHeap.pop();
        }
        sort(answer.begin(),answer.end());
        return answer;
    }