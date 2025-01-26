#include <bits/stdc++.h>
using namespace std;
vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> answer(n);
        stack<int> s;
        for(int i = n-1;i>=0;i--){
            while(s.size()){
                int topElement = s.top();
                if(topElement>arr[i]){
                    answer[i] = topElement;
                    break;
                }
                else{
                    s.pop();
                }
            }
            if(s.empty()){
                answer[i] = -1;
            }
            s.push(arr[i]);
        }
        return answer;
    }