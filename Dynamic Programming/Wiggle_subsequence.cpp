// https://leetcode.com/problems/wiggle-subsequence/
class Solution {
public:
    int wiggleMaxLength(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int> > dp(2, vector<int>(n, 1));
        // 0 state means rising at the tail
        // 1 state means drowning at the tail
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] > arr[j]) {
                    dp[0][i] = max(dp[0][i], 1 + dp[1][j]);
                }

                if (arr[i] < arr[j]) {
                    dp[1][i] = max(dp[1][i], 1 + dp[0][j]);
                }
            }
        }

        return max(*std::max_element(dp[0].begin(), dp[0].end()),
                   *std::max_element(dp[1].begin(), dp[1].end()));
    }
};