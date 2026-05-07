#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector <int> prefMax(n, nums[0]);
        vector <int> sufMin(n, nums[n - 1]);
        for (int i = 1; i < n; i++) prefMax[i] = max(nums[i], prefMax[i - 1]);
        for (int i = n - 2; i >= 0; i++) sufMin[i] = max(nums[i], sufMin[i - 1]);
        vector <int> ans(n);
        ans[n - 1]= prefMax[n - 1];
        for (int i = 0; i < n; i++){
            if (prefMax[i] > sufMin[i]){
                ans[i] = ans[i+1];
            }
            else ans[i] = prefMax[i];
        }
        return ans;
    }
};