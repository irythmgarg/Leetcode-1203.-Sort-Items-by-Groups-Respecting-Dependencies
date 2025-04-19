class Solution {
public:
    // Topological sort function to determine the order of nodes without cycles
    vector<int> topological(unordered_map<int,vector<int>>& mp, int n) {
        vector<int> indegree(n, 0);

        // Calculating indegrees for each node
        for (auto& [node, neighbors] : mp) {
            for (int neighbor : neighbors)
                indegree[neighbor]++;
        }

        queue<int> q;

        // Adding nodes with zero indegree to the queue
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> ans;
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for (int neighbor : mp[top]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If not all nodes are processed, there's a cycle
        if (ans.size() != n) return {};
        return ans;
    }

    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        // Assign unique group IDs to ungrouped items
        for (int i = 0; i < n; i++) {
            if (group[i] == -1)
                group[i] = m++;
        }

        // Mapping each item to its group
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[i] = group[i];
        }

        unordered_map<int, vector<int>> adjgrp;        // Graph for group dependencies
        unordered_map<int, vector<int>> adjindividual; // Graph for item dependencies

        // Building dependency graphs
        for (int i = 0; i < n; i++) {
            for (int before : beforeItems[i]) {
                if (mp[before] != mp[i]) {
                    adjgrp[mp[before]].push_back(mp[i]); // Inter-group dependency
                }
                adjindividual[before].push_back(i);       // Intra-group dependency
            }
        }

        // Topological sort on group and item graphs
        vector<int> grouporder = topological(adjgrp, m);
        vector<int> individualorder = topological(adjindividual, n);

        // Cycle check: If any order is empty, return empty result
        if (grouporder.empty() || individualorder.empty()) return {};

        // Grouping items based on their group order
        unordered_map<int, vector<int>> groupedItems;
        for (int item : individualorder) {
            groupedItems[mp[item]].push_back(item);
        }

        // Assembling final sorted list based on group ordering
        vector<int> mainans;
        for (int grp : grouporder) {
            for (int item : groupedItems[grp]) {
                mainans.push_back(item);
            }
        }

        return mainans;
    }
};
