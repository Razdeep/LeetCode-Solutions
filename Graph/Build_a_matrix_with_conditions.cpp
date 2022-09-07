// https://leetcode.com/problems/build-a-matrix-with-conditions/
class Solution {
public:
    
    vector<int> topologicalSort(vector<vector<int> >& conditions, int k) {
        vector<vector<int> > graph(k + 1);
        vector<int> in_degree(k + 1, 0);
        vector<int> visited(k + 1, false);
        
        for (const auto& condition: conditions) {
            graph[condition[0]].push_back(condition[1]);
            in_degree[condition[1]]++;
        }
        
        queue<int> q;
        
        for (int node = 1; node <= k; ++node) {
            if (in_degree[node] == 0) {
                q.push(node);
            }
        }
        
        vector<int> res;
        
        while (not q.empty()) {
            int parent = q.front();
            q.pop();
            res.push_back(parent);
            for (int connected: graph[parent]) {
                in_degree[connected]--;
                if (in_degree[connected] == 0) {
                    if (!visited[connected]) {        
                        visited[connected] = true;
                        q.push(connected);
                    }
                }
            }
        }
        
        return res;
    }
    
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        
        vector<vector<int> > ans(k, vector<int>(k, 0));
        auto row_order = topologicalSort(rowConditions, k);
        auto column_order = topologicalSort(colConditions, k);
        
        // detecting cycles
        if (row_order.size() != k or column_order.size() != k) {
            vector<vector<int>> empty_ans;
            return empty_ans; 
        }
        
        map<int, int> inverted_index;
        for (int i = 0; i < column_order.size(); ++i) {
            inverted_index[column_order[i]] = i;
        }
        
        for (int i = 0; i < row_order.size(); ++i) {
            int node_y = inverted_index[row_order[i]];
            ans[i][node_y] = row_order[i];
        }
        
        return ans;
    }
};