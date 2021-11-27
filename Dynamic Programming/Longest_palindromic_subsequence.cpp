// https://leetcode.com/problems/longest-palindromic-subsequence
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = int(s.size());
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
        
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i < n - len + 1; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && len == 2) {
                    dp[i][j] = 2;
                } else if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
};