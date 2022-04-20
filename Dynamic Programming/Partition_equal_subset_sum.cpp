// https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
public:
    bool knapsack(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int> > dp(n, vector<int>(target + 1, 0));
        
        for (int i = 0; i < n; ++i) {
            dp[i][0] = 1;
        }
        
        if (nums[0] < target) {
            dp[0][nums[0]] = 1;
        }
        
        for (int cur_target = 0; cur_target <= target; ++cur_target) {
            for (int i = 0; i < n; ++i) {
                if (i - 1 >= 0) {
                    dp[i][cur_target] |= dp[i - 1][cur_target];
                }
                if (i - 1 >= 0 and cur_target - nums[i] >= 0) {
                    dp[i][cur_target] |= dp[i - 1][cur_target - nums[i]];
                }
            }
        }
        
        return dp[n - 1][target];
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        if (sum & 1) {
            return false;
        }
        
        return knapsack(nums, sum / 2);
    }
};