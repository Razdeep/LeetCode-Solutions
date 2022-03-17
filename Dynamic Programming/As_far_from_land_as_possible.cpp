// https://leetcode.com/problems/as-far-from-land-as-possible/
class Solution {
public:
    bool inRange(int x, int y, int n) {
        return x >= 0 and y >= 0 and x < n and y < n;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = int(grid.size());
        vector<vector<int> > dp(n, vector<int>(n, 0));
        
        queue<pair<int, int> > q1, q2;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    q1.push({i, j});
                }
                dp[i][j] = grid[i][j];
            }
        }
        
        int steps = 2;
        
        while (!q1.empty()) {
            while (!q1.empty()) {
                auto elem = q1.front();
                q1.pop();
                int x = elem.first;
                int y = elem.second;
                if (inRange(x - 1, y, n) and dp[x - 1][y] == 0) {
                    q2.push({x - 1, y});
                    dp[x - 1][y] = steps;
                }
                if (inRange(x, y - 1, n) and dp[x][y - 1] == 0) {
                    q2.push({x, y - 1});
                    dp[x][y - 1] = steps;
                }
                if (inRange(x + 1, y, n) and dp[x + 1][y] == 0) {
                    q2.push({x + 1, y});
                    dp[x + 1][y] = steps;
                }
                if (inRange(x, y + 1, n) and dp[x][y + 1] == 0) {
                    q2.push({x, y + 1});
                    dp[x][y + 1] = steps;
                }
            }
            swap(q1, q2);
            ++steps;
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans == 1 ? -1 : ans - 1;
    }
};