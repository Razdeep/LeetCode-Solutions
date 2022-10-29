// https://leetcode.com/contest/weekly-contest-316/problems/number-of-subarrays-with-gcd-equal-to-k/
class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        
        int n = int(nums.size());
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            int cur_gcd = nums[i];
            for (int j = i; j < n; ++j) {
                cur_gcd = __gcd(cur_gcd, nums[j]);
                ans += cur_gcd == k;
            }
        }
        
        return ans;
    }
};