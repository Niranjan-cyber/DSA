#include <bits/stdc++.h>
using namespace std;


// gravity problem 
// one pointer increases one by one and second is rigidly placed

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> & boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();

        vector<vector<char>> v(n, vector <char> (m, 0));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                v[j][m - i - 1] = boxGrid[i][j];
            }
        }
        for (int j = 0; j < m; j++){
           int d = n - 1;
           for (int i = n -1; i >= 0; i--){
                if (v[i][j] == '*'){
                    d = i - 1;
                }
                else if (v[i][j] == '#'){
                    swap(v[i][j], v[d][j]);
                    d--;
                }
           }
        }
        return v;
    }
};