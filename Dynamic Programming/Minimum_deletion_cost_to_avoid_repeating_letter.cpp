// https://leetcode.com/problems/minimum-deletion-cost-to-avoid-repeating-letters/
class Solution {
    #define all(v) (v).begin(), (v).end()
    #define trace(x) cout << #x << ": " << x << endl;
public:
    int minCost(string s, vector<int>& cost) {
        int ans = 0;
        int n = int(s.size());
        vector<int> consecutive_costs;
        consecutive_costs.push_back(cost[0]);
        int i = 1;
        for (i = 1; i < n; ++i) {
            if (s[i] == s[i - 1]) {
                consecutive_costs.push_back(cost[i]);
            } else {
                sort(all(consecutive_costs));
                ans += accumulate(all(consecutive_costs), 0) - consecutive_costs.back();
                consecutive_costs.clear();
                consecutive_costs.push_back(cost[i]);
            }
        }
        if (!consecutive_costs.empty()) {
            sort(all(consecutive_costs));
            ans += accumulate(all(consecutive_costs), 0) - consecutive_costs.back();
            consecutive_costs.clear();
        }
        return ans;
    }
};