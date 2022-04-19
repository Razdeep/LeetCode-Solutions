// https://leetcode.com/problems/longest-turbulent-subarray/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = int(arr.size());
        
        vector<vector<int> > dp(n, vector<int>(2, 1));
        
        int ans = 1;
        
        for (int i = 1; i < n; ++i) {
            if (arr[i] > arr[i - 1]) {
                dp[i][0] = 1 + dp[i - 1][1];
            } else if (arr[i] < arr[i - 1]) {
                dp[i][1] = 1 + dp[i - 1][0];
            }
            ans = max({ans, dp[i][0], dp[i][1]});
        }
        
        return ans;
    }
};