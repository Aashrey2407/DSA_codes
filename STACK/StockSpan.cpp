#include <bits/stdc++.h>
using namespace std;
vector<int> calculateSpan(vector<int>& arr) {
        // write code here
        int n = arr.size();
        vector<int> answer(n);
        stack<pair<int,int>> s;
        for(int i = 0;i<n;i++){
            while(s.size()){
                int topElement = s.top().first;
                int topElementIndex = s.top().second;
                if(topElement>arr[i]){
                    answer[i] = i-topElementIndex;
                    break;
                }
                else{
                    s.pop();
                }
            }
            if(s.empty()){
                answer[i] = i+1;
            }
            s.push({arr[i],i});
        }
        return answer;
    }