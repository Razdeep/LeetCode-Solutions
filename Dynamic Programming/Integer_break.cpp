// https://leetcode.com/problems/integer-break

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        
        for (int i = 1; i <= n; ++i) {
            dp[i] = i - 1;
        }
        
        for (int num = 3; num <= n; ++num) {
            for (int last_term = 1; last_term < num; ++last_term) {
                dp[num] = max(dp[num], last_term * max(num - last_term, dp[num - last_term]));
            } 
        }
        
        return dp[n];
    }
};