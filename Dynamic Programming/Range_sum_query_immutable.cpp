// https://leetcode.com/problems/range-sum-query-immutable/

class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int>& nums) {
        const int n = int(nums.size());
        dp.resize(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int i, int j) {
        return dp[j + 1] - dp[i];
    }
};