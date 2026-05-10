#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> isPrime;

    void buildSieve(int maxEl) {
        isPrime.resize(maxEl + 1, true);

        if (maxEl >= 0) isPrime[0] = false;
        if (maxEl >= 1) isPrime[1] = false;

        for (int num = 2; num * num <= maxEl; num++) {
            if (isPrime[num]) {
                for (int multiple = num * num; multiple <= maxEl; multiple += num) {
                    isPrime[multiple] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();

        int maxE = *max_element(nums.begin(), nums.end());

        buildSieve(maxE);

        // value -> indices
        unordered_map<int, vector<int>> m;

        for (int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> visited(n, false);

        q.push(0);
        visited[0] = true;

        unordered_set<int> usedPrime;

        int steps = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                int i = q.front();
                q.pop();

                if (i == n - 1) return steps;

                // left
                if (i - 1 >= 0 && !visited[i - 1]) {
                    visited[i - 1] = true;
                    q.push(i - 1);
                }

                // right
                if (i + 1 < n && !visited[i + 1]) {
                    visited[i + 1] = true;
                    q.push(i + 1);
                }

                // prime teleport
                if (isPrime[nums[i]] && !usedPrime.count(nums[i])) {

                    for (int multiple = nums[i]; multiple <= maxE; multiple += nums[i]) {

                        if (!m.count(multiple)) continue;

                        for (int idx : m[multiple]) {

                            if (!visited[idx]) {
                                visited[idx] = true;
                                q.push(idx);
                            }
                        }
                    }

                    usedPrime.insert(nums[i]);
                }
            }

            steps++;
        }

        return -1;
    }
};