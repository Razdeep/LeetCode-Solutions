// https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
// Not accepted due to 100ms latency
#pragma GCC optimize ("O3")
class Solution {
    static constexpr int MOD = int(1e9) + 7;
    static constexpr int MAX = int(1e3) + 1;
    int dp[MAX][MAX];
    int cache[MAX][MAX];
public:
    
    inline int calculateWaysIfkAndnGiven(short i, short j) {
        
        if (cache[i][j] != -1) {
            return cache[i][j];
        }
        
        int res = 0;
            
        for (short last_block = 1; last_block + 1 <= i; ++last_block) {
            res += (dp[i - last_block][j - 1] % MOD);
            res %= MOD;
        }
        
        return cache[i][j] = res % MOD;
    }
    
    int numberOfSets(short n, short k) {
        memset(cache, -1, (MAX * MAX) * sizeof(int));
        for (short i = 0; i < MAX; ++i) {
            dp[i][0] = 1;
        }
        
        for (short i = 1; i <= n; ++i) {
            for (short j = 1; j <= k; ++j) {
                // if I skip the current rod
                dp[i][j] = dp[i - 1][j] % MOD;
                // if I take x rods one by one
                // Note here we are reducing the complexity from
                // O(n * n * k) to O(n * k) with memoization
                dp[i][j] += calculateWaysIfkAndnGiven(i, j);
                dp[i][j] %= MOD;
            }
        }
        
        return dp[n][k];
    }
};