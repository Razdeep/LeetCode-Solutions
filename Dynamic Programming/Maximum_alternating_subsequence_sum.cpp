// https://leetcode.com/problems/maximum-alternating-subsequence-sum/
class Solution {
    vector<vector<long long> > cache;
public:
    long long solve(vector<int>& nums, int idx, bool is_odd_idx) {
        if (idx >= int(nums.size())) {
            return 0;
        }
        
        if (cache[idx][is_odd_idx] != -1) {
            return cache[idx][is_odd_idx];
        }
        
        long long cur = is_odd_idx ? -nums[idx] : nums[idx];
        
        return cache[idx][is_odd_idx] = max(cur + solve(nums, idx + 1, !is_odd_idx), solve(nums, idx + 1, is_odd_idx));
    }
    
    long long maxAlternatingSum(vector<int>& nums) {
        cache.resize(int(1e5) + 14, vector<long long>(2, -1));
        return solve(nums, 0, false);
    }
};