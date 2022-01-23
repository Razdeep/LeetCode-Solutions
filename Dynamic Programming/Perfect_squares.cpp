// https://leetcode.com/problems/perfect-squares/

class Solution {
    typedef long long ll;
public:
    int numSquares(int n) {
        vector<ll> dp(n + 1, 0);
        
        for (ll i = 0; i <= n; ++i) {
            dp[i] = i;
        }
        
        for (ll num = 1; num <= n; ++num) {
            for (ll square_term = 1; square_term * square_term <= num; ++square_term) {
                ll square = square_term * square_term;
                dp[num] = min(dp[num], 1 + dp[num - square]);
            }
        }

        return dp[n];
    }
};