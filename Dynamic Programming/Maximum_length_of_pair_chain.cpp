// https://leetcode.com/problems/maximum-length-of-pair-chain/

class Solution {
public:
    static bool byMethod(vector<int> a, vector<int> b) {
        if (a[1] == b[1]) {
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), byMethod);
        
        int n = int(pairs.size());
        
        vector<int> dp(n, 1);
        dp[0] = 1;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[j][1] < pairs[i][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
    
        return *max_element(dp.begin(), dp.end());
    }
};