// https://leetcode.com/contest/weekly-contest-332/problems/count-the-number-of-fair-pairs/
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        
        int i = 0;
        
        for (int it: nums) {
            int reqd_lower = lower - it;
            auto lower_idx = lower_bound(nums.begin() + i + 1, nums.end(), reqd_lower) - nums.begin();
            
            int reqd_upper = upper - it;
            auto upper_idx = upper_bound(nums.begin() + i + 1, nums.end(), reqd_upper) - nums.begin() - 1;
            
            int contri = upper_idx - lower_idx + 1;
            
            if (contri > 0) {
                ans += contri;
            }
            ++i;
        }
        
        return ans;
    }
};