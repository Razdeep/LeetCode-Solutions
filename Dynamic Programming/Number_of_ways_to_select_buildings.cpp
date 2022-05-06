// https://leetcode.com/problems/number-of-ways-to-select-buildings/
class Solution {
public:
    long long numberOfWays(string s) {
        int n = int(s.size());
        long long cnt_ones = 0;
        
        for (const auto& letter: s) {
            cnt_ones += (letter == '1');
        }
        long long cnt_zeros = n - cnt_ones;
        
        vector<long long> prefix_ones(n, 0);
        vector<long long> prefix_zeros(n, 0);
        
        if (s[0] == '1') {
            prefix_ones[0] = 1;
        } else {
            prefix_zeros[0] = 1;
        }
        
        for (int i = 1; i < n; ++i) {
            prefix_ones[i] = prefix_ones[i - 1] + (s[i] == '1');
            prefix_zeros[i] = prefix_zeros[i - 1] + (s[i] == '0');
        }
        
        long long ans = 0;
        
        for (int i = 1; i + 1 < n; ++i) {
            if (s[i] == '1') {
                ans += prefix_zeros[i] * (cnt_zeros - prefix_zeros[i]);
            } else {
                ans += prefix_ones[i] * (cnt_ones - prefix_ones[i]);
            }
        }
        
        return ans;
        
    }
};