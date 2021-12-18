// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

class Solution {
public:
    int minimumDeletions(string s) {
        
        if (s.size() <= 1) {
            return 0;
        }
        
        int n = int(s.size());
        
        vector<int> prefix_a(n, 0), prefix_b(n, 0);
        prefix_a[0] = s[0] == 'a';
        prefix_b[0] = s[0] == 'b';
        
        for (int i = 1; i < n; ++i) {
            prefix_a[i] += prefix_a[i - 1] + (s[i] == 'a');
            prefix_b[i] += prefix_b[i - 1] + (s[i] == 'b');
        }
        
        int ans = min(prefix_a.back(), prefix_b.back());
        
        for (int i = 0; i < n; ++i) {
            ans = min(ans, prefix_b[i] + prefix_a[n - 1] - prefix_a[i]);
            ans = min(ans, prefix_b[i] + prefix_a[n - 1] - prefix_a[i]);
        }
        
        return ans;
    }
};