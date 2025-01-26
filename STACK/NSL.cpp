#include <bits/stdc++.h>
using namespace std;
vector<int> leftSmaller(int n, int a[]){
        // code here
        vector<int> answer(n);
        stack<int> s;
        for(int i = 0;i<n;i++){
            while(s.size()){
                int topElement = s.top();
                if(topElement<a[i]){
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
            s.push(a[i]);
        }
        return answer;
    }