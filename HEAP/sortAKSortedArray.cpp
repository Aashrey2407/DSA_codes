#include <bits/stdc++.h>
using namespace std;
vector < int > nearlySorted(vector < int > array, int n, int k) {
    // Write your code here.
    priority_queue<int,vector<int>,greater<int>> minHeap;
    for(int i = 0;i<=k;i++){
        minHeap.push(array[i]);
    }
    int index = 0;
    vector<int> sortedArray(n);
    for(int i = k+1;i<n;i++){
        int topElement = minHeap.top();
        minHeap.pop();
        sortedArray[index++] = topElement;
        minHeap.push(array[i]);
    }
    while(minHeap.size()){
        int topElement = minHeap.top();
        minHeap.pop();
        sortedArray[index++] = topElement;
    }
    return sortedArray;
}