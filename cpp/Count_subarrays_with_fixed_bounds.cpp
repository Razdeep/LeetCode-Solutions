// https://leetcode.com/contest/weekly-contest-315/problems/count-subarrays-with-fixed-bounds/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int start = 0;
        int n = nums.size();
        
        int min_k_index = -1;
        int max_k_index = -1;
        long long ans = 0;
        
        for (int i = 0; i < n; ++i) {
            
            if (nums[i] < minK or nums[i] > maxK) {
                start = i + 1;
                min_k_index = -1;
                max_k_index = -1;
                continue;
            }
            
            if (nums[i] == minK) {
                min_k_index = i;
            }
            
            if (nums[i] == maxK) {
                max_k_index = i;
            }
            
            if (min_k_index != -1 and max_k_index != -1) {
                int total_arrays_from_starting = i - start + 1;
                int arrays_to_be_deleted = i - min(min_k_index, max_k_index);
                ans += total_arrays_from_starting - arrays_to_be_deleted;
            }
            
        }
        
        return ans;
    }
};