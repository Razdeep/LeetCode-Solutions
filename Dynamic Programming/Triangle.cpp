// https://leetcode.com/problems/triangle/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int levels = int(triangle.size());
        vector<vector<int> > dp(levels, vector<int>(0));
        dp[0].push_back({triangle[0][0]});
        
        for (int level = 1; level < levels; ++level) {
            for (int idx = 0; idx < int(triangle[level].size()); ++idx) {
                if (idx == 0) {
                    // only right parent exists
                    int right_parent = dp[level - 1][idx];
                    int candidate = right_parent + triangle[level][idx];
                    dp[level].push_back(candidate);
                } else if (idx + 1 == int(triangle[level].size())) {
                    // only left parent exists
                    int left_parent = dp[level - 1][idx - 1];
                    int candidate = left_parent + triangle[level][idx];
                    dp[level].push_back(candidate);
                } else {
                    // both parent exist
                    int left_parent = dp[level - 1][idx - 1];
                    int right_parent = dp[level - 1][idx];
                    int candidate = triangle[level][idx] + min(left_parent, right_parent);
                    dp[level].push_back(candidate);
                }
            }
        }
        
        return *min_element(dp[levels - 1].begin(), dp[levels - 1].end());

    }
};