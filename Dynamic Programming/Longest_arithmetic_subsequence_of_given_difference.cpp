// https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = int(arr.size());
        map<int, int> dp;
        
        for (int i = 0; i < n; ++i) {
            auto itr = dp.find(arr[i] - difference);
            if (itr == dp.end()) {
                dp[arr[i]] = 1;
            } else {
                dp[arr[i]] = itr->second + 1;
            }
        }
        
        int ans = 0;
        for (const auto& it: dp) {
            ans = max(ans, it.second);
        }
        
        return ans;
    }
};