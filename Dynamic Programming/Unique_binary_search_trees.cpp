// https://leetcode.com/problems/unique-binary-search-trees/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        
        for (int no_of_nodes = 2; no_of_nodes <= n; ++no_of_nodes) {
            for (int root = 1; root <= no_of_nodes; ++root) {
                dp[no_of_nodes] += dp[root - 1] * dp[no_of_nodes - root];
            }
        }
        
        return dp[n];
    }
};