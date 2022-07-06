// https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
class Solution {
public:
    int minInsertions(string s) {
        // the answer is the length of the string - length of longest palindrome subsequence
        
        int n = int(s.size());
        
        vector<vector<int> > dp(n, vector<int>(n, 0));
        
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (j == i + 1) {
                        dp[i][j] = 2;
                    } else {
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    }
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return n - dp[0][n - 1];
    }
};