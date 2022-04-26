// https://leetcode.com/problems/super-ugly-number/
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        /**
         * Sometimes vectors doesnot work but raw integer arrays do :P
         */
        // vector<int> dp(n, 1);
        int dp[int(1e6)];
        dp[0] = 1;
        // vector<int> multiplier_index(primes.size(), 0);
        int multiplier_index[101] = {0};
        
        for (int i = 1; i < n; ++i) {
            int min_so_far = INT_MAX;
            for (int mul_idx = 0; mul_idx < primes.size(); ++mul_idx) {
                int j = mul_idx; // since sizes of both array the same
                min_so_far = min(min_so_far, primes[j] * dp[multiplier_index[mul_idx]]);
            }
            dp[i] = min_so_far;
            
            for (int mul_idx = 0; mul_idx < primes.size(); ++mul_idx) {
                int j = mul_idx; // since sizes of both array the same
                if (min_so_far == primes[j] * dp[multiplier_index[mul_idx]]) {
                    multiplier_index[mul_idx]++;
                }
            }
        }
        
        return dp[n - 1];
    }
};