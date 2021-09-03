// https://leetcode.com/problems/egg-drop-with-2-eggs-and-n-floors/

class Solution {
public:
    int twoEggDrop(int n) {
        vector<vector<int> > dp(3, vector<int>(n + 1, INT_MAX));
        
        dp[1][1] = 1;
        dp[2][1] = 1;
        dp[2][0] = 0;
        
        for (int i = 0; i <= n; ++i) {
            dp[0][i] = 0;
            dp[1][i] = i;
        }
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                dp[2][i] = min(dp[2][i], 
                               1 + max(dp[2][i - j], dp[1][j - 1]));
            }
        }
        
        return dp[2][n];
    }
};