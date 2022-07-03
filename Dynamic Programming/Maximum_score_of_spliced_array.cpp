// https://leetcode.com/problems/maximum-score-of-spliced-array/
class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2) {
        int n = int(nums1.size());
        vector<vector<int> > dp(3, vector<int>(n + 1, 0));
        
        // Using 1-indexing
        
        dp[0][1] = nums1[0];
        
        for (int i = 1; i < n; ++i) {
            dp[0][i + 1] = dp[0][i] + nums1[i];
        }
        
        for (int i = 0; i < n; ++i) {
            dp[1][i + 1] = max(dp[0][i + 1], dp[1][i] + nums2[i]);
        }
        
        for (int i = 0; i < n; ++i) {
            dp[2][i + 1] = max(dp[1][i + 1], dp[2][i] + nums1[i]);
        }
        
        return dp[2][n];
    }
    
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        return max(solve(nums1, nums2), solve(nums2, nums1));
    }
};