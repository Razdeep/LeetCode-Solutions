// https://leetcode.com/problems/combination-sum-iv/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // Trick is to change int to unsigned int
        vector<unsigned int> dp(target + 1, 0);
        
        int n = int(nums.size());
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] <= target) {
                dp[nums[i]] = 1;
            }
        }
        
        for (int cur_target = 1; cur_target <= target; ++cur_target) {
            for (int i = 0; i < n; ++i) {
                if (cur_target >= nums[i]) {
                    dp[cur_target] += dp[cur_target - nums[i]];
                }
            }
        }
        
        return dp[target];
    }
};