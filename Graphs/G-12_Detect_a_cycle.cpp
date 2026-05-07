#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int i, vector <vector <int>> &adj, vector <bool> &visited){
        visited[i] = true;
        queue <pair <int, int>> q;
        q.push({i, -1});
        while (!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto it : adj[node]){
                if (!visited[it]){
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (it != parent){
                    return true;
                }
            }
        }
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector <vector <int>> adj(numCourses);
        for (auto it : prerequisites) adj[it[0]].push_back(it[1]);
        vector <bool> visited(numCourses, false);

        for (int i = 0; i < numCourses; i++){
            if (!visited[i]){
                if (check(i, adj, visited)) return false;
            } 
        }
        return true;
    }
};