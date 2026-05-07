#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int n = nums.size();
        vector <int> p(n), s(n);
        p[0] = nums[0];
        for (int i = 1; i < n; i++){
            p[i] = max(p[i - 1], nums[i]);
        }
        s[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) s[i] = min(s[i - 1], nums[i]);

        int len;
        for (int i = n - 2; i >= 0; i--){
            if (p[i] <= s[i + 1]) len = i + 1;
        }
        return len;
    }
};