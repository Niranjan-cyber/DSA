#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector <int> ans;
        int n = nums.size();
        for (int i = n - 1; i >= 0; i--){
            int ele = nums[i];
            while (ele > 0){
                ans.push_back(ele % 10);
                ele = ele / 10;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};