#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1, ans = nums[0];
        while (l <= r){
            int m = (l + r) / 2;
            if (nums[m] < ans){
                ans = nums[m];
                r = m - 1;
            }
            else l = m + 1;
        }
        return ans;
    }
};