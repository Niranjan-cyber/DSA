#include <bits/stdc++.h>
using namespace std;

// also works for 768

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunks = 1;
        vector <int> p(n), s(n);
        p[0] = arr[0], s[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++) p[i] = max(p[i - 1], arr[i]);  
        for (int i = n-2; i >= 0; i--) s[i] = min(s[i + 1], arr[i]);
        
        for (int i = n - 2; i >= 0; i--){
            if (p[i] <= s[i + 1]) chunks++;
        }
        return chunks;
    }
};