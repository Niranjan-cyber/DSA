#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector <vector <int>> visited(n, vector <int> (m, 0));
        vector <vector <int>> region(n, vector <int> (m, 0));
        
        queue <pair <int, int>>q;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (board[i][j] == 1 && !visited[i][j]){
                    if (i == 0 || i == n - 1 || j == 0 || j == m - 1){
                        visited[i][j] = 1;
                        q.push({i, j});
                    }
                }
            }
        }
        int delr[] = {1, 0, -1 , 0};
        int delc[] = {0, 1, 0, -1};

        while (!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            region[row][col] = 1;
            q.pop();
            for (int i = 0; i < 4; i++){
                int newr = row + delr[i];
                int newc = col + delc[i];

                if (newr >= 0 && newr < n && newc >= 0 && newc < m){
                    if (!visited[newr][newc] && board[newr][newc] == 1){
                        visited[newr][newc]=1;
                        q.push({newr, newc});
                    }
                }
            }
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (region[i][j] == 1) board[i][j] = 0;
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //vector <vector <int>> visited(n, vector <int> (m, 0));
        solve(grid);
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j ++){
                if (grid[i][j] == 1){
                    ans++;
                }
            }
        }
        return ans;
    }
};


