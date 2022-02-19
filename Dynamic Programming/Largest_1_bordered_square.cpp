// https://leetcode.com/problems/largest-1-bordered-square/
class Solution {
public:
    
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        vector<vector<int> > vertical_sum(rows, vector<int>(cols));
        vector<vector<int> > horizontal_sum(rows, vector<int>(cols));
        
        for (int i = 0; i < cols; ++i) {
            vertical_sum[0][i] = grid[0][i];
        }
        
        for (int i = 0; i < rows; ++i) {
            horizontal_sum[i][0] = grid[i][0];
        }
        
        int ans = 0; // turned to 1, if any 1 is present in grid
        
        for (int i = 1; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j]) {
                    ans = 1;
                    vertical_sum[i][j] = 1 + vertical_sum[i - 1][j];
                }
            }
        }
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (grid[i][j]) {
                    ans = 1;
                    horizontal_sum[i][j] = 1 + horizontal_sum[i][j - 1];
                }
            }
        }
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int max_attempt = min(horizontal_sum[i][j], vertical_sum[i][j]);
                for (int cur_attempt = max_attempt; cur_attempt > 0; --cur_attempt) {
                    if (vertical_sum[i][j - cur_attempt + 1] >= cur_attempt and horizontal_sum[i - cur_attempt + 1][j] >= cur_attempt) {
                        ans = max(ans, cur_attempt * cur_attempt);
                    }
                }
            }
        }
        
        return ans;
    }
};