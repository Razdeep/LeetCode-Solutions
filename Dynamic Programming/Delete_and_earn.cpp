// https://leetcode.com/problems/delete-and-earn/

class Solution {
    constexpr static int MAX = int(1e4) + 5;
public:
    int deleteAndEarn(vector<int>& nums) {
        
        // this problem is similar to house robbing problem
        
        vector<int> freq(MAX, 0);
        for (int i = 0; i < int(nums.size()); ++i) {
            freq[nums[i]]++;
        }
        
        vector<int> sums;
        
        for (int i = 0; i < int(freq.size()); ++i) {
            sums.push_back(freq[i] * i);
        }
        
        // sums will be the main array from this point
        
        vector<int> dp(sums.size());
        dp[0] = sums[0];
        dp[1] = sums[1];
        
        for (int i = 2; i < int(sums.size()); ++i) {
            dp[i] = max(dp[i - 1], sums[i] + dp[i - 2]);
        }
        
        return dp.back();
    }
};