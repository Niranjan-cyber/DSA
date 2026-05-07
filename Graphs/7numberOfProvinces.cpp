#include <bits/stdc++.h>
using namespace std;

// TC : O(v^2) 
// SC : O(n) visited + O(n) queue

// one solution is use adjacentcy list and then do
class Solution {
public:
    void bfs(int i, vector <int> &visited, vector <vector <int>> &mat){
        queue<int> q;
        q.push(i);
        visited[i] = 1;
        while (!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                int node = q.front();
                q.pop();
                for (int j = 0; j < mat.size(); j++){
                    if (mat[node][j] && visited[j] == 0){
                        visited[j] = 1;
                        q.push(j);
                    } 
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector <int> visited(isConnected.size());
        int v = isConnected.size();
        int ans = 0;
        for (int i = 0; i < v; i++){
            if(visited[i] == 0){
                bfs(i, visited, isConnected);
                ans++; 
            }     
        }
        return ans;
    }
};