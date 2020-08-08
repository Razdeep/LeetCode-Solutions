// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (int(prices.size() <= 1)) {
            return 0;
        }
        
        constexpr int oo = int(1e9);
        int n = int(prices.size());
        vector<int> minimum_price_till(n, oo);
        vector<int> maximum_price_till(n, -oo);
        
        minimum_price_till[0] = prices[0];
        for (int i = 1; i < n; ++i) {
            minimum_price_till[i] = min(minimum_price_till[i - 1], prices[i]);
        }
        
        maximum_price_till[n - 1] = prices[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maximum_price_till[i] = max(maximum_price_till[i + 1], prices[i]);
        }
        
        int res = -oo;
        
        for (int i = 0; i + 1 < n; ++i) {
            res = max(res, maximum_price_till[i] - minimum_price_till[i]);
        }
        
        return res;
    }
};
