// https://leetcode.com/problems/coin-change/
class Solution {
    static constexpr int oo = int(1e9) + 7;
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = int(coins.size());
        sort(coins.begin(), coins.end());
        
        if (amount == 0 or n == 0) {
            return 0;
        }
        
        if (n == 1) {
            return amount % coins[0] == 0 ? amount / coins[0] : -1;
        }
        
        vector<vector<int> > dp(n, vector<int>(amount + 1, oo));
        
        for (int i = 0; i < n; ++i) {
            if (coins[i] <= amount) {
                dp[i][coins[i]] = 1;
            }
        }
        
        for (int i = 0; i <= amount; i += coins[0]) {
            dp[0][i] = i / coins[0];
        }
        
        for (int i = 1; i < n; ++i) {
            for (int cur_amount = 0; cur_amount <= amount; ++cur_amount) {
                 dp[i][cur_amount] = min({
                        dp[i - 1][cur_amount], dp[i][cur_amount]});
                if (cur_amount - coins[i] >= 0) {
                    dp[i][cur_amount] = min({
                        dp[i][cur_amount], 
                        1 + dp[i][cur_amount - coins[i]]
                    });
                }
            }
        }
        
        return dp[n - 1][amount] == oo ? -1 : dp[n - 1][amount];
    }
};