#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> dfs(int m, int n, vector<vector<int>>& image, int sr, int sc, int color, int og){
        if (sr < 0 || sr >= m || sc < 0 || sc >= n) return;
        if (image[sr][sc] == color) return;
        if (image[sr][sc] == og){
            image[sr][sc] = color;
            dfs(m, n, image, sr + 1, sc, color, og);
            dfs(m, n, image, sr - 1, sc, color, og);
            dfs(m, n, image, sr , sc - 1, color, og);
            dfs(m, n, image, sr, sc + 1, color, og);
        }
        else return; 
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        dfs(m, n, image, sr, sc, color, image[sr][sc]);
        return image;
    }
};