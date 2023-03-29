#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_set<pair<int, int>> edges;
        unordered_map<int, vector<int>> neighbors;
        unordered_set<int> visit;
        int changes = 0;

        for (auto& connection : connections) {
            int a = connection[0], b = connection[1];
            edges.insert({a, b});
            neighbors[a].push_back(b);
            neighbors[b].push_back(a);
        }

        function<void(int)> dfs = [&](int city) {
            for (int neighbor : neighbors[city]) {
                if (visit.count(neighbor)) continue;
                if (!edges.count({neighbor, city})) changes++;
                visit.insert(neighbor);
                dfs(neighbor);
            }
        };

        visit.insert(0);
        dfs(0);
        return changes;
    }
};
