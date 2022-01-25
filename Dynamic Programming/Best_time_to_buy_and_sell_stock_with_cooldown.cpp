// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = int(prices.size());
        vector<vector<int> > profit(n, vector<int>(3, 0));
        
        profit[0][0] = -prices[0];
        
        enum State {BOUGHT_STATE, SOLD_STATE, COOLDOWN_STATE};
        
        for (int i = 1; i < n; ++i) {
            profit[i][BOUGHT_STATE] = max(profit[i - 1][BOUGHT_STATE], profit[i - 1][COOLDOWN_STATE] - prices[i]);
            profit[i][SOLD_STATE] = max(profit[i - 1][SOLD_STATE], prices[i] + profit[i - 1][BOUGHT_STATE]);
            profit[i][COOLDOWN_STATE] = max({profit[i - 1][COOLDOWN_STATE], profit[i - 1][SOLD_STATE], profit[i - 1][BOUGHT_STATE]});
        }
        
        return profit[n - 1][SOLD_STATE];
    }
};