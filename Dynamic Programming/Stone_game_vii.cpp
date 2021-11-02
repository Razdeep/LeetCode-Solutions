// https://leetcode.com/problems/stone-game-vii/
class Solution {
public:
    vector<vector<int> > dp;
    
    int helper(vector<int>& stones, int i, int j, int sum) {
        if (i == j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int first_option = sum - stones[i] - helper(stones, i + 1, j, sum - stones[i]);
        int second_option = sum - stones[j] - helper(stones, i, j - 1, sum - stones[j]);
        return dp[i][j] = max(first_option, second_option);
    }
    
    int stoneGameVII(vector<int>& stones) {
        int n = int(stones.size());
        dp.resize(n, vector<int>(n, -1));
        
        int sum_score = std::accumulate(stones.begin(), stones.end(), 0);
        return helper(stones, 0, n - 1, sum_score);
    }
        
};