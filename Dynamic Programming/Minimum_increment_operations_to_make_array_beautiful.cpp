// https://leetcode.com/contest/weekly-contest-369/problems/minimum-increment-operations-to-make-array-beautiful/
class Solution {
public:
    long long minIncrementOperations(vector<int>& nums, int k) {
        
        long long ans = LONG_LONG_MAX;
        
        const int n = static_cast<int>(nums.size());
        
        vector<long long> dp(n, 0);
        
        dp[0] = max(0, k - nums[0]);

        for (int i = 0; i < n; ++i) {
            int ops_reqd_current = max(0, k - nums[i]);
            
            long long ops_reqd_from_prev = LONG_LONG_MAX;
            
            for (int j = 1; j <= 3; ++j) {
                long long candidate_prev = i - j >= 0 ? dp[i - j] : 0;
                ops_reqd_from_prev = min(ops_reqd_from_prev, candidate_prev);
            }
            
            dp[i] = ops_reqd_current + ops_reqd_from_prev;
        }
        
        for (int i = n - 1; i >= n - 3; --i) {
            ans = min(ans, dp[i]);
        }
        
        return ans;
    }
};