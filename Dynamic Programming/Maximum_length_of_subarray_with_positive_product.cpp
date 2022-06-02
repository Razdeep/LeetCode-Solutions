// https://leetcode.com/problems/maximum-length-of-subarray-with-positive-product/
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = int(nums.size());
        int first_negative_idx_in_cur_range = -1;
        int last_zero_idx_so_far = -1;
        int negative_count_in_cur_range = 0;
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                // resetting everything
                last_zero_idx_so_far = i;
                first_negative_idx_in_cur_range = -1;
                negative_count_in_cur_range = 0;
            } else {
                if (nums[i] < 0) {
                    if (first_negative_idx_in_cur_range == -1) {
                        first_negative_idx_in_cur_range = i;
                    }
                    negative_count_in_cur_range++;                  
                }
                
                if (negative_count_in_cur_range % 2 == 0) {
                    ans = max(ans, i - last_zero_idx_so_far);
                } else {
                    ans = max(ans, i - first_negative_idx_in_cur_range);
                }
            }
        }
        
        return ans;
    }
};