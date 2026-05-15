#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l = 0, h = n - 1, ans = nums[0];
        while (l <= h){
            int m = l + (h - l)/2;
            if (nums[m] < nums[h]){
                ans = min(ans, nums[m]);
                h = m;
            }
            else if(nums[m] > nums[h]) l = m + 1;
            else{
            if (nums[m] == nums[h]){
                ans = min(ans, nums[m]);
                h--;
            } 
            } 
        }
        return ans;
    }
};