#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int steps = 0;
        vector <bool> visited(n, false);
        queue <int> q;
        q.push(0);
        visited[0] = true;
        map <int, vector <int>> mp;
        for (int i = 0; i < n; i++){
            mp[arr[i]].push_back(i);
        }
        while (!q.empty()){
            int size = q.size();
            while (size--){
                int i = q.front();
                q.pop();
                if (i == n - 1) return steps;
                if (i + 1 < n && !visited[i + 1]){
                    q.push(i+1);
                    visited[i+1] = true;
                }
                if (i - 1 >= 0 && !visited[i - 1]){
                    q.push(i-1);
                    visited[i-1] = true;
                }
                for (auto it : mp[arr[i]]){
                    if (!visited[it]){
                        q.push(it);
                        visited[it] = true;
                    }
                }
                mp[arr[i]].clear();
            }
            steps++;
        }
        return steps;
    }
};