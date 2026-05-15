#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector <int> ans;
        vector <vector <int>> matrix (n, vector <int> (n)); 
        for (int i = 1; i <= n; i++) ans.push_back(i);
        int layers = (n + 1) / 2;
        int idx = 0;
        for (int i = 0; i < layers; i++){
            int top = i, left = i;
            int bottom = n - i - 1;
            int right = n - i - 1;
            for (int j = left; j <= right; j++) matrix[top][j] = ans[idx++];
            for (int j = top + 1; j <= bottom; j++) matrix[j][right] = ans[idx++];
            if (top!=bottom)for (int j = right - 1; j >= left; j--) matrix[bottom][j] = ans[idx++];
            if(left!=right)for (int j = bottom - 1; j > top; j--) matrix[j][left] = ans[idx++];
        }
        return matrix;
    }
};