class Solution {
public:
    const int oo = int(1e9);
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = int(matrix.size());
        vector<vector<int> > dp(n, vector<int>(n, oo));
        
        for (int i = 0; i < n; ++i) {
            dp[0][i] = matrix[0][i];
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (j == 0) {
                    dp[i][0] = matrix[i][0] + min(dp[i - 1][0], dp[i - 1][1]);
                } else if (j == n - 1) {
                    dp[i][n - 1] = matrix[i][n - 1] + min(dp[i - 1][n - 2], dp[i - 1][n - 1]);
                } else {
                    dp[i][j] = matrix[i][j] + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i - 1][j + 1]));
                }
            }
        }
        
        int ans = oo;
        for (int i = 0; i < n; ++i) {
            ans = min(ans, dp[n - 1][i]);
        }
        return ans;
    }
};