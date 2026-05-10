#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int layers = (min(m, n) + 1)/2;
        for (int i = 0; i < layers; i++){
            int top = i, left = i;
            int bottom = m - i - 1, right = n - i - 1;
            vector <int> ans;
            for (int j = left; j <= right; j++) ans.push_back(matrix[top][j]);
            for (int j = top + 1; j <= bottom; j++) ans.push_back(matrix[j][right]);
            if (top!=bottom)for (int j = right - 1; j >= left; j--) ans.push_back(matrix[bottom][j]);
            if(left!=right)for (int j = bottom - 1; j > top; j--) ans.push_back(matrix[j][left]);   
            std::rotate(ans.begin(), ans.end() - (right - left), ans.end());
            int idx = 0;
            for (int j = left; j <= right; j++) matrix[top][j] = ans[idx++];
            for (int j = top + 1; j <= bottom; j++) matrix[j][right] = ans[idx++];
            if (top!=bottom)for (int j = right - 1; j >= left; j--) matrix[bottom][j] =ans[idx++];
            if(left!=right)for (int j = bottom - 1; j > top; j--) matrix[j][left] = ans[idx++];   
        }
        return;
    }
};