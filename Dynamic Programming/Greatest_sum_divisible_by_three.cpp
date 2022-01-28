// https://leetcode.com/problems/greatest-sum-divisible-by-three/
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int n = int(nums.size());
        vector<vector<int> > dp(3, vector<int>(n + 1, 0));
        
        dp[1][0] = INT_MIN;
        dp[2][0] = INT_MIN;
        
        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] % 3 == 0) {
                dp[0][i] = max(dp[0][i - 1], nums[i - 1] + dp[0][i - 1]);
                dp[1][i] = max(dp[1][i - 1], nums[i - 1] + dp[1][i - 1]);
                dp[2][i] = max(dp[2][i - 1], nums[i - 1] + dp[2][i - 1]);
            } else if (nums[i - 1] % 3 == 1) {
                dp[0][i] = max(dp[0][i - 1], nums[i - 1] + dp[2][i - 1]);
                dp[1][i] = max(dp[1][i - 1], nums[i - 1] + dp[0][i - 1]);
                dp[2][i] = max(dp[2][i - 1], nums[i - 1] + dp[1][i - 1]);
            } else if (nums[i - 1] % 3 == 2) {
                dp[0][i] = max(dp[0][i - 1], nums[i - 1] + dp[1][i - 1]);
                dp[1][i] = max(dp[1][i - 1], nums[i - 1] + dp[2][i - 1]);
                dp[2][i] = max(dp[2][i - 1], nums[i - 1] + dp[0][i - 1]);
            }
        }
        
        return dp[0][n];
    }
};