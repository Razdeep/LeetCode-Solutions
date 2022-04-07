// https://leetcode.com/problems/domino-and-tromino-tiling/
class Solution {
    typedef long long ll;
    static constexpr int MOD = int(1e9) + 7;
public:
    int numTilings(int n) {
        // Linear dp with O(n^2) complexity
        // We can also make it O(n) with some black magic
        
        vector<ll> dp(n + 1, 0ll);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j + 2 < i; ++j) {
                dp[i] += (2ll * dp[j]);
                dp[i] %= MOD;
            }
            dp[i] += dp[i - 1];
            dp[i] %= MOD;
            dp[i] += dp[i - 2];
            dp[i] %= MOD;
        }
        
        return dp[n];
    }
};