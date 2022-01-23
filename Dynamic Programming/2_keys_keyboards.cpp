// https://leetcode.com/problems/2-keys-keyboard/

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        
        for (int i = 2; i <= n; ++i) {
            dp[i] = i;
        }
        
        for (int num = 3; num <= n; ++num) {
            for (int j = 1; j < num; ++j) {
                if (num % j == 0) {
                    // 1 for copy; num / j - 1 for pasting
                    dp[num] = min(dp[num], dp[j] + 1 + (num / j -  1));
                }
            }
        }
        
        return dp[n];
    }
};