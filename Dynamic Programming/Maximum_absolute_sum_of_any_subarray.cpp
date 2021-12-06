// https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // inspired from kadane's algorithm
        int max_positive_sum = 0;
        int min_negative_sum = 0;
        int cur_positive_sum = 0;
        int cur_negative_sum = 0;
        int n = int(nums.size());

        for (int i = 0; i < n; ++i) {
            if (cur_positive_sum + nums[i] > 0) {
                cur_positive_sum += nums[i];
                max_positive_sum = max(max_positive_sum, cur_positive_sum);
            } else {
                cur_positive_sum = 0;
            }
            
            if (cur_negative_sum + nums[i] < 0) {
                cur_negative_sum += nums[i];
                min_negative_sum = min(cur_negative_sum, min_negative_sum);
            } else {
                cur_negative_sum = 0;
            }
        }
        
        return max(max_positive_sum, -min_negative_sum);
    }
};