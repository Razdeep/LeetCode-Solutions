// https://leetcode.com/problems/minimum-cost-for-tickets/
class Solution {
public:
    const int oo = int(1e9);
    #define trace(x) cout << #x << ": " << x << endl;
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int no_of_days = int(days.size());
        vector<int> dp(no_of_days, 0);
        
        int min_ticket_price = *std::min_element(costs.begin(), costs.end());
        
        for (int i = 0; i < no_of_days; ++i) {
            dp[i] = min_ticket_price * (i + 1);
        }
        
        for (int i = 1; i < no_of_days; ++i) {
            
            dp[i] = min(dp[i], dp[i - 1] + costs[0]);
            
            int k = i;
            while (k >= 0 && days[k] + 30 > days[i]) {
                --k;
            }

            if (k == -1) {
                dp[i] = min(dp[i], costs[2]);
            } else {
                dp[i] = min(dp[i], dp[k] + costs[2]);
            }

            k = i;
            while (k >= 0 && days[k] + 7 > days[i]) {
                --k;
            }

            if (k == -1) {
                dp[i] = min(dp[i], costs[1]);
            } else {
                dp[i] = min(dp[i], dp[k] + costs[1]);
            }
            
        }
        
        return dp[no_of_days - 1];
    }
};