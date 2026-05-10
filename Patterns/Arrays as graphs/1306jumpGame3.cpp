#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (arr[start] == 0) return true;
        int n = arr.size();
        vector <bool> visited(n, false);
        
        queue <int> q;
        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            int size = q.size();
            while (size--){
                int idx = q.front();
                q.pop();
                if (arr[idx] == 0) return true;
                if (idx + arr[idx] <= n - 1 && !visited[idx + arr[idx]]){
                    q.push(idx + arr[idx]);
                    visited[idx + arr[idx]] = true;
                }
                if (idx - arr[idx] >= 0 && !visited[idx - arr[idx]]){
                    q.push(idx - arr[idx]);
                    visited[idx - arr[idx]] = true;
                }
            }
        }
        return false;
        
    }
};