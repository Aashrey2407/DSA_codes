// problem link: https://www.geeksforgeeks.org/problems/search-in-a-matrix17201720/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card
#include <bits/stdc++.h>
using namespace std;
bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        int rows = mat.size();
        int cols = mat[0].size();
        int i = 0;
        int j = cols-1;
        while(i>=0 && i<rows && j>=0 && j<cols){
            if(mat[i][j]==x){
                return true;
            }
            else if(mat[i][j]>x){
                j--;
            }
            else{
                i++;
            }
        }
        return false;
    }