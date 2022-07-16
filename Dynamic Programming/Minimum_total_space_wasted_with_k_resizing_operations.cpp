// https://leetcode.com/problems/minimum-total-space-wasted-with-k-resizing-operations/
class Solution {
    static constexpr int oo = int(1e9);
public:
    int minSpaceWastedKResizing(vector<int>& nums, int resizes_allowed) {
        int no_of_elems = int(nums.size());
        vector<vector<int> > dp(no_of_elems, vector<int>(resizes_allowed + 1, oo));
        
        dp[0][0] = 0;
        
        vector<int> max_till(no_of_elems, 0), sum_till(no_of_elems, 0);
        max_till[0] = sum_till[0] = nums[0];

        for (int i = 1; i < no_of_elems; ++i) {
            max_till[i] = max(max_till[i - 1], nums[i]);
            sum_till[i] = sum_till[i - 1] + nums[i];
            dp[i][0] = ((i + 1) * max_till[i]) - sum_till[i];
        }
        
        for (int i = 1; i < no_of_elems; ++i) {
            for (int j = 1; j <= resizes_allowed; ++j) {
                int max_in_range = 0;
                int sum_in_range = 0;
                
                // If I resize at k-th index
                for (int k = i; k >= 1; --k) {
                    max_in_range = max(nums[k], max_in_range);
                    sum_in_range += nums[k];
                    int length_of_range = (i - k + 1);
                    int partial_contribution = (max_in_range * length_of_range) - sum_in_range;
                    int potential_ans = partial_contribution + dp[k - 1][j - 1];
                    dp[i][j] = min(dp[i][j], potential_ans);
                }
            }
        }
        
        return dp[no_of_elems - 1][resizes_allowed];
    }
};