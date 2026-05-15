#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector <int> p(n), s(n), ans(n);
        p[0] =arr[0];
        s[n - 1] = arr[n - 1];
        for (int i = 1; i < n; i++) p[i] = p[i - 1] * arr[i];
        for (int i = n - 2; i >= 0; i--) s[i] = s[i + 1] * arr[i];

        for (int i = 0;i < n;i++){
            int prod = 1;
            if (i > 0) prod *= p[i - 1];
            if (i < n - 1) prod *= s[i+1];
            ans[i] = prod;
        }
        return ans;
    }
};