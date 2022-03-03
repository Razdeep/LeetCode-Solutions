// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = int(arr.size());
        vector<vector<int> > dp(n, vector<int>(n, 2));
        map<int, int> locationOf;
        
        for (int i = 0; i < n; ++i) {
            locationOf[arr[i]] = i;
        }
        
        for (int i = 0; i < n; ++i) {
            dp[i][i] = 1;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int next_elem = arr[i] + arr[j];
                auto location_itr = locationOf.find(next_elem);
                if (location_itr != locationOf.end()) {
                    dp[j][location_itr->second] = max(dp[j][location_itr->second], dp[i][j] + 1);
                }
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, int(*std::max_element(dp[i].begin(), dp[i].end())));
        }
        
        return ans == 2 ? 0 : ans;
    }
};