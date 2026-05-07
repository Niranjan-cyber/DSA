#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(n);
        int l = 0, r = n - 1;
        for (int i = 0; i < n; i++){
            if (nums[i] % 2 == 0){
                ans[l] = 0;
                l++;
            }
            else {
                ans[r] = 1;
                r--;
            }
        }
        return ans;
    }
};