// https://leetcode.com/contest/weekly-contest-354/problems/minimum-index-of-a-valid-split/
class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        
        int n = static_cast<int>(nums.size());
        map<int, int> suffix_map, prefix_map;
        
        for (int num: nums) {
            ++suffix_map[num];
        }
        
        for (int i = 0; i < n; ++i) {
            ++prefix_map[nums[i]];
            --suffix_map[nums[i]];
            
            if (2 * prefix_map[nums[i]] > (i + 1) and 2 * suffix_map[nums[i]] > (n - i - 1)) {
                return i;
            }
        }
        
        return -1;
    }
};