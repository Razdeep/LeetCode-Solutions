// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int n = int(nums.size());
        
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum == n) {
            return n - 1;
        }
        
        for (int i = 0; i < n; ) {
            int j = i;
            int zero_count = 0;
            int one_count = 0;
            int next_pos = -1;
            for (; j < n; ++j) {
                if (nums[j] == 0) {
                    zero_count++;
                    if (next_pos == -1) {
                        next_pos = j + 1;
                    }
                }
                if (zero_count > 1) {
                    break;
                }
                one_count += nums[j];
            }
            ans = max(ans, one_count);
            i = next_pos != -1 ? next_pos : j + 1;
        }
        
        return ans;
    }
};