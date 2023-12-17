// https://leetcode.com/contest/weekly-contest-370/problems/maximum-score-after-applying-operations-on-a-tree/

class Solution {
    
    enum State {KEPT_ABOVE, KEPT_HERE, KEPT_BELOW, STATE_COUNT};
    static constexpr int ROOT = 0;
    static constexpr long long oo = static_cast<long long>(1e14) + 7;
    
public:
    void dfs(int current, int parent, const vector<vector<int> >& graph, 
                vector<vector<long long> >& dp, const vector<int>& values) {
        
        if (1 == graph[current].size() and current != ROOT) {
            dp[KEPT_ABOVE][current] = values[current];
            dp[KEPT_HERE][current] = 0;
            dp[KEPT_BELOW][current] = -oo;
            return;
        }
        
        dp[KEPT_ABOVE][current] += values[current];
        dp[KEPT_HERE][current] += 0;
        dp[KEPT_BELOW][current] += values[current];
        
        for (int child: graph[current]) {
            if (child == parent) {
                continue;
            }
            dfs(child, current, graph, dp, values);
            dp[KEPT_ABOVE][current] += dp[KEPT_ABOVE][child];
            dp[KEPT_HERE][current] += dp[KEPT_ABOVE][child];
            dp[KEPT_BELOW][current] += max(dp[KEPT_HERE][child], dp[KEPT_BELOW][child]);
        }
    }
    
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        
        const int n = static_cast<int>(values.size());
        vector<vector<long long> > dp(3, vector<long long>(n, 0));
        
        vector<vector<int> > graph(n, vector<int>(0));
        
        for (const auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        dfs(0, -1, graph, dp, values);
        
        return max(dp[KEPT_HERE][0], dp[KEPT_BELOW][0]);
    }
};