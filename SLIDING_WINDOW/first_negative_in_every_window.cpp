#include <bits/stdc++.h>
using namespace std;
vector<int> FirstNegativeInteger(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        int start = 0;
        int end = 0;
        queue<int> q;
        vector<int> answer;
        while(end<n){
            if(arr[end]<0){
                q.push(arr[end]);
            }
            if(end-start+1==k){
                if(q.empty()){
                    answer.push_back(0);
                }
                else{
                    answer.push_back(q.front());
                    if(q.front()==arr[start]){
                    q.pop();
                }
                }
                start++;
            }
            end++;
        }
        return answer;
    }