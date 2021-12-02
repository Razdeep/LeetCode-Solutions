// https://leetcode.com/problems/flip-string-to-monotone-increasing/
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = int(s.size());
        vector<int> cnt_ones(n, 0);
        vector<int> cnt_zeros(n, 0);
        
        cnt_zeros[0] = (s[0] == '0');
        cnt_ones[0] = (s[0] == '1');
        
        for (int i = 1; i < n; ++i) {
            cnt_zeros[i] = cnt_zeros[i - 1] + (s[i] == '0');
            cnt_ones[i] = cnt_ones[i - 1] + (s[i] == '1');
        }
        
        string copy_s = s;
        sort(copy_s.begin(), copy_s.end());
        if (s == copy_s) {
            return 0;
        }
        
        // we are turning all of them 1s or 0s here, this is the worst case to start with
        int ans = min(cnt_zeros[n - 1], cnt_ones[n - 1]);
        
        for (int i = 0; i < n; ++i) {
            ans = min(ans, cnt_ones[i] + (cnt_zeros[n - 1] - cnt_zeros[i]));
        }
        
        return ans;
    }
};