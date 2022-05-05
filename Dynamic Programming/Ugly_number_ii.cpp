// https://leetcode.com/problems/ugly-number-ii/
class Solution {
    static constexpr long long oo = 1e18;
public:
    int nthUglyNumber(int n) {
        unordered_set<long long> st;
        
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        
        vector<long long> multipliers(3, 1);
        vector<long long> values;
        values.push_back(2);
        values.push_back(3);
        values.push_back(5);
        int i = 2;
        
        while (dp.size() <= n) {
            long long winner = oo;
            int min_multiplier_idx = -1;
            for (int j = 0; j < 3; ++j) {
                long long candidate = dp[multipliers[j]] * values[j];
                if (candidate <= winner) {
                    winner = candidate;
                    min_multiplier_idx = j;
                }
            }
            if (st.find(winner) == st.end()) {
                dp.push_back(winner);
            }
            st.insert(winner);
            multipliers[min_multiplier_idx]++;
        }
        
        return dp[n];
    }
};