// https://leetcode.com/problems/solving-questions-with-brainpower/
class Solution {
    
    #define POINTS 0
    #define BRAINPOWER 1
    
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        
        vector<long long> dp(n, 0);
        dp[n - 1] = questions[n - 1][POINTS];
            
        for (int i = n - 2; i >= 0; --i) {
            int next_solvable_question_idx = i + questions[i][BRAINPOWER] + 1;
            dp[i] = questions[i][POINTS];
            if (next_solvable_question_idx < n) {
                dp[i] += dp[next_solvable_question_idx];
            }
            dp[i] = max(dp[i], dp[i + 1]);
        }
        
        return dp[0];
    }
};