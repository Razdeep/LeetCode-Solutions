// https://leetcode.com/problems/minimum-sideway-jumps/

class Solution {
    static constexpr int oo = int(1e9);
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = int(obstacles.size());

        vector<vector<int> > road(3, vector<int>(n + 1, 0));
        vector<vector<int> > dp(3, vector<int>(n + 1, oo));
        
        for (int i = 0; i < n; ++i) {
            if (obstacles[i]) {
                road[obstacles[i] - 1][i] = 1;
            }
        }
        
        dp[0][0] = dp[2][0] = 1;
        dp[1][0] = 0; 
        
        for (int i = 1; i <= n; ++i) {
            for (int lane = 0; lane <= 2; ++lane) {
                if (road[lane][i] == 0) {
                    dp[lane][i] = min(dp[lane][i], dp[lane][i - 1]);
                }
            }
            if (road[0][i] == 0) {
                dp[0][i] = min({dp[0][i], 1 + dp[1][i], 1 + dp[2][i]});
            }
            if (road[1][i] == 0) {
                dp[1][i] = min({dp[1][i], 1 + dp[0][i], 1 + dp[2][i]});
            }
            if (road[2][i] == 0) {
                dp[2][i] = min({dp[2][i], 1 + dp[1][i], 1 + dp[0][i]});
            }
        }
        
        return min({dp[0][n], dp[1][n], dp[2][n]});
    }
};