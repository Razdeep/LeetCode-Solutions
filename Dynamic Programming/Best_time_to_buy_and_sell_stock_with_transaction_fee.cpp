// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = int(prices.size());
        if (n <= 1) {
            return 0;
        }
        vector<vector<int> > dp(2, vector<int>(n, 0));
        
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        
        for (int i = 1; i < n; ++i) {
            dp[0][i] = max(dp[0][i - 1], dp[1][i - 1] - prices[i]);
            dp[1][i] = max(dp[1][i - 1], dp[0][i - 1] + prices[i] - fee);
        }
        
        return max(dp[0][n - 1], dp[1][n - 1]);
    }
};