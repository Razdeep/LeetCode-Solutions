// https://leetcode.com/problems/ones-and-zeroes/
class Solution {
    static constexpr int oo = int(1e9);
    static constexpr int N = 601;
    static constexpr int ONES_LIMIT = 101;
    static constexpr int ZEROS_LIMIT = 101;
    char cache[ONES_LIMIT][ZEROS_LIMIT][N];
public:
    
    inline int countZeros(const string& s) {
        int res = 0;
        for (const auto& it: s) {
            res += it == '0';
        }
        return res;
    }
    
    inline int helper(vector<string>& strs, int remaining_zeros, int remaining_ones, int index) {
        if (remaining_zeros >= 0 and remaining_ones >= 0 and index >= 0 and cache[remaining_zeros][remaining_ones][index] != -1) {
            return cache[remaining_zeros][remaining_ones][index];
        }
        if (index >= int(strs.size())) {
            return remaining_ones >= 0 and remaining_zeros >= 0 ? 0 : -oo;
        }
        
        int cnt_zeros = countZeros(strs[index]);
        int cnt_ones = int(strs[index].size()) - cnt_zeros;
        
        int picked_ans = 0;
        if (remaining_zeros - cnt_zeros >= 0 and  remaining_ones - cnt_ones >= 0) {
            picked_ans = 1 + helper(strs, remaining_zeros - cnt_zeros, remaining_ones - cnt_ones, index + 1);
        }
    
        int not_picked_ans = helper(strs, remaining_zeros, remaining_ones, index + 1);
        
        if (remaining_zeros >= 0 and remaining_ones >= 0 and index >= 0) {
            cache[remaining_zeros][remaining_ones][index] = max(picked_ans, not_picked_ans);
        }
        return max(picked_ans, not_picked_ans);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(cache, -1, ZEROS_LIMIT * ONES_LIMIT * N * sizeof(char));
        return max(0, helper(strs, m, n, 0));
    }
};