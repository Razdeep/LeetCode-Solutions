// https://leetcode.com/problems/reducing-dishes/
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = int(satisfaction.size());
        sort(satisfaction.rbegin(), satisfaction.rend());
        
        int total_sum = 0;
        int current_sum = 0;
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            current_sum += satisfaction[i];
            total_sum += current_sum;
            ans = max(ans, total_sum);
        }
        
        return ans;
    }
};