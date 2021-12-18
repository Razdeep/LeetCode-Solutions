// https://leetcode.com/problems/coin-change-2/
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int no_of_denominations = int(coins.size());
        
        vector<vector<int> > dp(no_of_denominations, vector<int>(amount + 1, 0));
        
        for (int i = 0; i <= amount; ++i) {
            dp[0][i] = (i % coins[0] == 0);
        }
        
        for (int i = 0; i < no_of_denominations; ++i) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i <= amount; ++i) {
            for (int j = 1; j < no_of_denominations; ++j) {
                dp[j][i] = dp[j - 1][i];
                for (int k = 1; coins[j] * k <= i; ++k) {
                    dp[j][i] += dp[j - 1][i - (coins[j] * k)];
                }
            }
        }
        
        return dp[no_of_denominations - 1][amount];
    }
};