#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if (source == target) return 0;
        int n = routes.size();
        map <int, vector <int>> mp;
        int stops = 0;
        for (int i = 0;i < n; i++){
            for (int j = 0; j < routes[i].size(); j++){
                mp[routes[i][j]].push_back(i);
                stops++;
            }
        }
        vector <bool> visited(stops, false);
        vector <bool> busVisited(n, false);
        queue <int> q;
        q.push(source);
        visited[source] = true;
        int steps = 1;
        while(!q.empty()){
            int size = q.size();
            while (size--){
                int stop = q.front();
                q.pop();
                vector <int> buses;
                for (auto &it : mp[stop]){
                    buses.push_back(it);
                }
                for (auto &it : buses){
                    if (busVisited[it]) continue;
                    busVisited[it] = true;
                    for (auto &i : routes[it]){
                        if (i == target) return steps;
                        if (!visited[i]){
                            q.push(i);
                            visited[i] = true;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};