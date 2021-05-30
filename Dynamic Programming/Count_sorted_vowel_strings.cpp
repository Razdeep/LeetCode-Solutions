// https://leetcode.com/problems/count-sorted-vowel-strings/

class Solution {
public:
    int countVowelStrings(int n) {
        n++;
        vector<vector<int> > dp(5, vector<int>(n, 0));
        
        for (int i = 0; i < 5; ++i) {
            dp[i][0] = 1;
        }
        
        for (int i = 0; i < n; ++i) {
            dp[4][i] = 1;
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 3; j >= 0; --j) {
                dp[j][i] = dp[j][i - 1] + dp[j + 1][i];
            }
        }
        
        return dp[0][n - 1];
    }
};