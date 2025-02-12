#include <bits/stdc++.h>
using namespace std;

int longestKSubstr(string &s, int k) {
    int n = s.size();
    int start = 0;
    int maxLength = -1;  // Initialize to -1 for cases where no valid substring exists
    unordered_map<char, int> mpp;

    for (int end = 0; end < n; end++) {
        mpp[s[end]]++;

        // Shrink the window until we have at most k distinct characters
        while (mpp.size() > k) {
            mpp[s[start]]--;
            if (mpp[s[start]] == 0) {
                mpp.erase(s[start]);
            }
            start++;  // Move the start pointer
        }

        // Only update maxLength if exactly k distinct characters exist
        if (mpp.size() == k) {
            maxLength = max(maxLength, end - start + 1);
        }
    }

    return maxLength;
}
