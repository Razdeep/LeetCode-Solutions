// https://leetcode.com/problems/guess-number-higher-or-lower-ii/
class Solution {
    static constexpr int oo = int(1e9);
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n, vector<int>(n, oo));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 0;
        }
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                for (int k = i; k < j; ++k) {
                    int down_val = k - 1 >= 0 ? dp[i][k - 1] : 0;
                    int up_val = k + 1 < j ? dp[k + 1][j] : 0;
                    int candidate = k + 1 + max(down_val, up_val);
                    if (candidate < dp[i][j]) {
                        dp[i][j] = candidate;
                    }
                }
            }
        }
        
        return dp[0][n - 1];
    }
};