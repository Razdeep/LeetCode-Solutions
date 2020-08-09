// https://leetcode.com/problems/maximum-subarray/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        if (int(nums.size()) == 1) {
            return nums[0];
        }
        
        constexpr int oo = int(1e9);
        const int n = int(nums.size());
        vector<int> dp(n, -oo);
        
        dp[0] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};