// https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

class Solution {
public:
    const int oo = int(1e9);
    int minimumDeleteSum(string s1, string s2) {
        int n = int(s1.size());
        int m = int(s2.size());
        
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, oo));
        
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                if (i == 0 && j == 0) {
                    dp[i][j] = 0;
                } else if (i == 0) {
                    dp[i][j] = dp[i][j - 1] + s2[j - 1];
                } else if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + s1[i - 1];
                } else if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(s2[j - 1] + dp[i][j - 1], s1[i - 1] + dp[i - 1][j]);
                }
            }
        }
        
        return dp[n][m];
    }
};