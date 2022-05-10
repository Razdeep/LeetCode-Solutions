// https://leetcode.com/problems/word-break/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet;
        
        for (int i = 0; i < int(wordDict.size()); ++i) {
            wordSet.insert(wordDict[i]);
        }
        
        int n = int(s.size());
        
        vector<int> dp(n, false);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                string last_word = s.substr(j, i - j + 1);
                if (wordSet.find(last_word) != wordSet.end()) {
                    dp[i] |= j - 1 >= 0 ? dp[j - 1] : true;
                }
            }
        }
        
        return dp[n - 1];
    }
};