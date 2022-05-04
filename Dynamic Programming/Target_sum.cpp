// https://leetcode.com/problems/target-sum/
class Solution {
public:
    int solve(vector<int>& nums, int idx, int remaining) {
        if (idx == nums.size()) {
            return remaining == 0;
        }
        int solution_a = solve(nums, idx + 1, remaining + nums[idx]);
        int solution_b = solve(nums, idx + 1, remaining - nums[idx]);
        
        return solution_a + solution_b;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, target);
    }
};