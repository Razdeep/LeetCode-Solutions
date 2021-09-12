// https://leetcode.com/problems/partition-array-for-maximum-sum/

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = int(arr.size());
        vector<int> dp(n, 0);

        dp[0] = arr[0];
        
        for (int i = 1; i < n; ++i) {
            int max_in_this_range = INT_MIN;
            int range_count = 1;
            for (int j = i; j >= max(0, i - k + 1); --j) {
                max_in_this_range = max(max_in_this_range, arr[j]);
                dp[i] = max(dp[i], 
                            (i - range_count >= 0 ? dp.at(i - range_count) : 0) 
                            + (max_in_this_range * range_count));
                range_count++;
            }
        }
    
        return dp[n - 1];
    }
};