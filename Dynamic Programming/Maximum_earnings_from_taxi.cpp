// https://leetcode.com/problems/maximum-earnings-from-taxi/
class Solution {
    enum Field { START, END, TIP };
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        
        sort(rides.begin(), rides.end(), [](const auto& a, const auto& b) {
            if (a[END] == b[END]) {
                return a[START] < b[START];
            }
            return a[END] < b[END];
        });
        
        vector<long long> dp(int(1e5) + 9, 0);
        
        dp[rides[0][END]] = rides[0][END] - rides[0][START] + rides[0][TIP];

        int prev_covered = rides[0][END];
        long long prev_ans = dp[rides[0][END]];
        
        for (int i = 1; i < int(rides.size()); ++i) {
            for (int j = prev_covered; j <= rides[i][END]; ++j) {
                dp[j] = max(dp[i], prev_ans);
            } 
            
            long long current_tip = rides[i][END] - rides[i][START] + rides[i][TIP];
            long long current_ans = max({ 
                                    current_tip, 
                                    current_tip + dp[rides[i][START]],
                                  });
            
            dp[rides[i][END]] = max(dp[rides[i][END]], current_ans);
            
            prev_covered = rides[i][END];
            prev_ans = max(prev_ans, current_ans);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};