// https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = int(word1.size());
        int m = int(word2.size());
        
        vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                }
            }
        }
        
        int lcs = dp[n][m];
        
        int ans = (n - lcs) + (m - lcs);
        
        return ans;
    }
};