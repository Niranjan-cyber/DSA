#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
        int n = arr.size();
        vector <int> p(n), s(n);
        p[0] = arr[0], s[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++) p[i] = max(p[i - 1], arr[i]);  
        for (int i = n-2; i >= 0; i--) s[i] = min(s[i + 1], arr[i]);

        int l = 0, r = n - 1;
        while (l < n - 1 && arr[l] <= arr[l+1]) l++;
        if (l == r) return 0;
        while (0 < r && arr[r] >= arr[r-1]) r--;
        int len = r - l + 1;
        
        while (r < n - 1 && p[r] > s[r+1]){
            len++;
            r++;
        }
        while (l > 0 && p[l - 1] >  s[l]){
            len++;
            l--;
        }
        return len;
    }
};