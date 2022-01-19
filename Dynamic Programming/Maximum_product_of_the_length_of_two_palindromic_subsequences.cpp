// https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/

class Solution {
    typedef long long ll;
public:
    
    ll lps(const string& text) {
        
        ll n = ll(text.size());
        
        if (n == 0) {
            return 0;
        }
        
        vector<vector<ll> > dp(n + 1, vector<ll>(n + 1, 0ll));
        
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1ll;
        }
        
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (text[i] == text[j] and len == 2) {
                    dp[i][j] = 2;
                } else if (text[i] == text[j]) {
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        
        return dp[0][n - 1];
    }
    
    int maxProduct(string s) {
        ll n = int(s.size());
        ll total_combinations = (1LL << n) - 1;
        
        ll ans = 0;
        
        for (int combination = 1; combination <= total_combinations; ++combination) {
            string subsequence_1 = "";
            string subsequence_2 = "";
            for (int i = 0; i < n; ++i) {
                if (combination & (1LL << i)) {
                    subsequence_1.push_back(s[i]);
                } else {
                    subsequence_2.push_back(s[i]);
                }
            }
            ans = max(ans, lps(subsequence_1) * lps(subsequence_2));
        }
        
        return ans;
    }
};