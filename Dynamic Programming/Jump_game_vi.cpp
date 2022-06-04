// https://leetcode.com/problems/jump-game-vi/
class Solution {
    static constexpr int oo = int(1e9);
    struct CustomCompare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first) {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
public:
    int maxResult(vector<int>& nums, int k) {
        int n = int(nums.size());
        vector<int> dp(n, -oo);
        
        dp[0] = nums[0];
        priority_queue<pair<int, int>, vector<pair<int, int> >, CustomCompare > pq;
        pq.push({nums[0], 0});
            
        for (int i = 1; i < n; ++i) {
            while (pq.size() and pq.top().second < i - k) {                
                pq.pop();
            }
            dp[i] = nums[i] + dp[pq.top().second];
            pq.push({dp[i], i});
        }
        
        return dp[n - 1];
    }
};