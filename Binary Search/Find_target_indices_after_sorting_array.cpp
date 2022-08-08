// https://leetcode.com/problems/find-target-indices-after-sorting-array/
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = int(nums.size());
        sort(nums.begin(), nums.end());
        vector<int> res;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == target) {
                res.push_back(i);
            }
        }
        
        return res;
    }
};