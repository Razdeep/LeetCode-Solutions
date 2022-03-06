// https://leetcode.com/problems/longest-arithmetic-subsequence/
class Solution {
    static constexpr int OFFSET_MAX = 2000;
    static constexpr int OFFSET = (OFFSET_MAX >> 1);
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = int(nums.size());
        vector<vector<int> > dp(n, vector<int>(OFFSET_MAX, 1));
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int x = nums[i], y = nums[j];
                int difference = x - y + OFFSET;
                dp[j][difference] = 1 + dp[i][difference];
                ans = max(ans, dp[j][difference]);
            }
        }
        
        return ans;
    }
};