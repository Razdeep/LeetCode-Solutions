// https://leetcode.com/problems/maximal-square/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = int(matrix.size());
        int m = int(matrix[0].size());
        
        vector<vector<int> > dp(n, vector<int>(m, 0));
        
        int longest_side = 0;
        
        for (int i = 0; i < n; ++i) {
            dp[i][0] = matrix[i][0] - '0';
            longest_side = max(longest_side, dp[i][0]);
        }
        
        for (int i = 0; i < m; ++i) {
            dp[0][i] = matrix[0][i] - '0';
            longest_side = max(longest_side, dp[0][i]);
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    longest_side = max(longest_side, dp[i][j]);
                }
            }
        }
        
        int area = longest_side * longest_side;
        return area;
    }
};