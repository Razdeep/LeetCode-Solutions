// https://leetcode.com/problems/largest-sum-of-averages/

class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = int(nums.size());
        
        vector<int> prefix_sum(n, 0);
        prefix_sum[0] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + nums[i];
        }
        
        vector<vector<double> > dp(k + 1, vector<double>(n, 0.0));
        
        for (int i = 0; i < n; ++i) {
            dp[1][i] = prefix_sum[i] / static_cast<double>(i + 1);
        }
        
        for (int i = 1; i <= k; ++i) {
            dp[i][0] = nums[0];
        }
        
        for (int i = 2; i <= k; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = prefix_sum[j] / static_cast<double>(j + 1);
                for (int l = j; l - 1 >= 0; --l) {
                    double average_of_tail = (prefix_sum[j] - prefix_sum[l - 1]) / static_cast<double> (j - l + 1);
                    double potential_ans = average_of_tail + dp[i - 1][l - 1];

                    dp[i][j] = max(dp[i][j], potential_ans);
                }
            }
        }
        
        
        return dp[k][n - 1];
    }
};