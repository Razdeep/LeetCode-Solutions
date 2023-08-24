// https://leetcode.com/problems/check-if-it-is-possible-to-split-array/description/

class Solution {
    
public:
    
    bool canSplitArray(vector<int>& nums, int m) {
        
        const int n = static_cast<int>(nums.size());
        
        if (n <= 1) return true;
        
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            prefix[i] += nums[i] + prefix[i - 1];
        }
        
        int start = 0, end = n - 1;
        bool ok = true;
        
        vector<vector<bool> > dp(n + 5, vector<bool>(n + 5, false));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = dp[i][i + 1] = true;
        }
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
            
                int j = i + len - 1;
                
                for (int k = i; k < j; ++k) {
                    bool condition_1 = (prefix[k] - (i - 1 >= 0 ? prefix[i - 1] : 0) >= m) or (k - i + 1 == 1);
                    bool condition_2 = (prefix[j] - prefix[k] >= m) or (j == k + 1);
                    
                    if (dp[i][k] and dp[k + 1][j] and condition_1 and condition_2) {
                        dp[i][j] = true;
                    }
                } 

            }
        }
        
        return dp[0][n - 1];
    }
};