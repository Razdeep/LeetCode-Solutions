// https://leetcode.com/problems/ways-to-make-a-fair-array/

class Solution {
    #define trace(x) cout << #x << ": " << x << endl;
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = int(nums.size());
        int ans = 0;
        
        if (n == 1) {
            return 1;
        }
        
        if (n == 2) {
            return nums[0] == nums[1] ? 0 : 2;
        }
        
        vector<int> prefix_odd_sum(n, 0);
        vector<int> prefix_even_sum(n, 0);
        prefix_even_sum[0] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            prefix_odd_sum[i] = prefix_odd_sum[i - 1];
            prefix_even_sum[i] = prefix_even_sum[i - 1];
            if (i & 1) {
                prefix_odd_sum[i] += nums[i];
            } else {
                prefix_even_sum[i] += nums[i];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            int odd_sum = (i - 1 >= 0 ? prefix_odd_sum[i - 1] : 0) + prefix_even_sum[n - 1] - prefix_even_sum[i];
            int even_sum = (i - 1 >= 0 ? prefix_even_sum[i - 1] : 0) + prefix_odd_sum[n - 1] - prefix_odd_sum[i];
            ans += (odd_sum == even_sum);
        }
        
        return ans;
    }
};