// https://leetcode.com/contest/weekly-contest-347/problems/minimum-cost-to-make-all-characters-equal/
class Solution {
public:
    long long minimumCost(string s) {
        int n = static_cast<int>(s.size());
        
        vector<long long> prefix_cost(n, 0), suffix_cost(n, 0);
        
        for (int i = 1; i < n; ++i) {
            if (s[i] != s[i - 1]) {
                prefix_cost[i] += prefix_cost[i - 1] + i;
            } else {
                prefix_cost[i] = prefix_cost[i - 1];
            }
        }
        
        for (int i = n - 2; i >= 0; --i) {
            if (s[i] != s[i + 1]) {
                suffix_cost[i] = suffix_cost[i + 1] + (n - i - 1);
            } else {
                suffix_cost[i] = suffix_cost[i + 1];
            }
        }
        
        long long ans = numeric_limits<long long>::max();
        
        for (int i = 0; i < n; ++i) {
            ans = min(prefix_cost[i] + suffix_cost[i], ans);
        }
        
        return ans;
    }
};