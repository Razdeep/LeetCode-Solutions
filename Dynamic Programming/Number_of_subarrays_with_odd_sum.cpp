// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
class Solution {
    static constexpr int MOD = int(1e9) + 7;
public:
    int numOfSubarrays(vector<int>& arr) {
        
        int n = int(arr.size());
        vector<int> prefix_sum(n, 0);
        
        prefix_sum[0] = arr[0];
        
        for (int i = 1; i < n; ++i) {
            prefix_sum[i] = arr[i] + prefix_sum[i - 1];
            prefix_sum[i] %= MOD;
        }
        
        int even_count_so_far = 0;
        int odd_count_so_far = 0;
        int ans = 0;
        
        // If current prefix sum is odd, then number of odd subarrays that
        // can be formed by this is cnt_even because odd - even == odd
        // Corner case: An extra 1 is added because what if we dont want 
        // to subtract any even array sum, it is still gonna be odd
        
        for (int i = 0; i < n; ++i) {
            if (prefix_sum[i] & 1) {
                ans += even_count_so_far + 1;
                ans %= MOD;
                odd_count_so_far++;
            } else {
                ans += odd_count_so_far;
                ans %= MOD;
                even_count_so_far++;
            }
        }
        
        return ans;
    }
};