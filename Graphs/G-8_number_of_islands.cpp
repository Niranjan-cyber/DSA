#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>&visited){
        int n = grid.size();
        int m = grid[0].size();
        queue <pair <int, int>> q;

        visited[i][j] = 1;
        q.push({i, j});

        int delr[] = {1, 0, -1, 0};
        int delc[] = {0, 1, 0, -1};

        while (!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i= 0; i < 4; i++){
                int newr = row + delr[i];
                int newc = col + delc[i];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m){
                    if (!visited[newr][newc] && grid[newr][newc] == '1'){
                        visited[newr][newc] = 1;
                        q.push({newr, newc});
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector <vector <int>> visited(n, vector <int> (m, 0));

        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j ++){
                if (grid[i][j] == '1' && !visited[i][j]){
                    ans++;
                    bfs(i, j, grid, visited);
                }
            }
        }
        return ans;
    }
};