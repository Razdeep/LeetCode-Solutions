// https://leetcode.com/problems/two-best-non-overlapping-events/

class Solution {
    
    #define trace(x) cout << #x << ": " << x << endl;
    enum Fields { START_TIME, END_TIME, VALUE };
    
public:
    
    int maxTwoEvents(vector<vector<int>>& events) {
        
        sort(events.begin(), events.end(), [](const auto& a, const auto& b) {
            if (a[END_TIME] == b[END_TIME]) {
                return a[VALUE] > b[VALUE];
            }
            return a[END_TIME] < b[END_TIME];
        });
        
        int n = int(events.size());
        vector<int> max_left(n, 0), dp(n, 0);
        
        dp[0] = max_left[0] = events[0][VALUE];
        
        for (int i = 1; i < n; ++i) {
            dp[i] = max_left[i] = max(events[i][VALUE], max_left[i - 1]);
        }
        
        for (int i = 1; i < n; ++i) {
            vector<int> current_event = events[i];
            
            int left = 0, right = i - 1;
            int target_idx = 0;
            
            while (right - left > 1) {
                int mid = (right + left) / 2;
                if (events[mid][END_TIME] >= current_event[START_TIME]) {
                    right = mid;
                } else {
                    target_idx = mid;
                    left = mid;
                }
            }
            
            int contri_from_left = 0;
            if (events[target_idx][END_TIME] < current_event[START_TIME]) {
                contri_from_left = max_left[target_idx];
            }
            
            dp[i] = max(dp[i], contri_from_left + current_event[VALUE]);
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};