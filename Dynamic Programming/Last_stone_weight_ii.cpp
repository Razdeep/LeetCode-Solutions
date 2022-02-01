// https://leetcode.com/problems/last-stone-weight-ii/
class Solution {
    constexpr static int oo = int(1e9);
    
public:
    int lastStoneWeightII(vector<int>& stones) {
        int stone_count = int(stones.size());
        
        if (stone_count <= 1) {
            return stones[0];
        }
        int sum = accumulate(stones.begin(), stones.end(), 0);
        
        // We need to find the closest thing to (sum / 2) we can form
        // sum = sum_1 + sum_2 ; trying to maximize sum_2 over a limit of sum/2
        
        vector<vector<int> > dp(stone_count, vector<int>(sum / 2 + 1, 0));
        
        for (int i = 0; i < stone_count; ++i) {
            dp[i][0] = 1;
        }
        
        dp[0][stones[0]] = 1;
        
        for (int stone_idx = 1; stone_idx < stone_count; ++stone_idx) {
            // Why copying? because it was reusing the destroyed stones
            // We dont want current results interfare in the ongoing current calculations
            auto temp = dp;
            for (int part_sum = 1; part_sum < int(dp[stone_idx].size()); ++part_sum) {
                if (part_sum - stones[stone_idx] >= 0 and dp[stone_idx - 1][part_sum - stones[stone_idx]]) {
                    temp[stone_idx][part_sum] = 1;
                }
                if (dp[stone_idx - 1][part_sum]) {
                    temp[stone_idx][part_sum] = 1;
                }
            }
            dp = temp;
        }
        
        int max_sum_2 = -oo;
        
        for (int i = 0; i < int(dp[0].size()); ++i) {
            if (dp[stone_count - 1][i]) {
                max_sum_2 = i;
            }
        }
        
        return sum - (max_sum_2 << 1);
    }
};