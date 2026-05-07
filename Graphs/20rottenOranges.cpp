#include <bits/stdc++.h>
using namespace std;

// now u have altered the grid but never do that u only visited

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        vector <vector <int>> visited(n, vector <int> (m, 0));
        queue <pair <int, int>> q;
        int fresh = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j  < m; j++){
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
                else if (grid[i][j] == 1) fresh++;
            }

        }
        int x[] = {1, -1, 0 , 0};
        int y[] = {0, 0, -1, +1}; 
        int ans = -1;
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                auto node = q.front();
                q.pop();

                int row = node.first, col = node.second;

                for (int j = 0; j < 4; j++){
                        int frow = row + x[j];
                        int fcol = col + y[j];
                        if (frow >= 0 && frow < n && fcol >= 0 && fcol < m &&
                        !visited[frow][fcol] && grid[frow][fcol] == 1){
                            grid[frow][fcol] = 2;
                            visited[frow][fcol] = 1;
                            fresh--;
                            // if (fresh == 0) return ans;
                            q.push({frow, fcol});
                        } 
                    }
                }
                ans++;
        }
        
        if (fresh) return -1;
        else if (fresh  =)
        else return ans;
    }
};