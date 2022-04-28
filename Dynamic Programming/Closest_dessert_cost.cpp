// https://leetcode.com/problems/closest-dessert-cost/
class Solution {
    set<int> possible_amounts;
public:
    void solve(int baseCost, vector<int>& toppingCosts, int index, int bill) {
        if (index >= toppingCosts.size()) {
            possible_amounts.insert(baseCost + bill);
            return;
        }
        solve(baseCost, toppingCosts, index + 1, bill);
        solve(baseCost, toppingCosts, index + 1, bill + toppingCosts[index]);
        solve(baseCost, toppingCosts, index + 1, bill + 2 * toppingCosts[index]);
    }
    
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        for (int i = 0; i < baseCosts.size(); ++i) {
            solve(baseCosts[i], toppingCosts, 0, 0);
        }
        int best_diff = INT_MAX;
        int ans = 0;
        for (auto possible_amount: possible_amounts) {
            if (abs(possible_amount - target) < best_diff) {
                best_diff = abs(possible_amount - target);
                ans = possible_amount;
            }
        }
        return ans;
    }
};