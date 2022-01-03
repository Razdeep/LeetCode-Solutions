// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = int(prices.size());
        long long current_streak = 1;
        long long ans = 0;
        
        for (int i = 1; i < n; ++i) {
            if (prices[i] + 1 == prices[i - 1]) {
                current_streak++;
            } else {
                ans += (current_streak + 1) * current_streak / 2;
                current_streak = 1;
            }
        }
        ans += (current_streak + 1) * current_streak / 2;
        
        return ans;
    }
};