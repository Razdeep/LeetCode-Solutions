// https://leetcode.com/problems/best-sightseeing-pair/
class Solution {
public:
    
    /**
    This problem is similar to stock maximizing problem
    */
    
    int maxScoreSightseeingPair(vector<int>& values) {
        int n = int(values.size());
        int ans = 0;
        int best_first_point = values[0] + 0;
        
        for (int i = 1; i < n; ++i) {
            ans = max(ans, best_first_point + values[i] - i);
            best_first_point = max(best_first_point, values[i] + i);
        }
        
        return ans;
    }
};