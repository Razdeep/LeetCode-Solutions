// https://leetcode.com/problems/cherry-pickup-ii
class Solution {
    static constexpr int oo = int(1e9);
    int cache[71][71][71];
public:
    int helper(vector<vector<int>>& grid, int i, int j1, int j2) {
        
        int n = int(grid.size());
        int m = int(grid[0].size());
        
        if (j1 < 0 or j1 >= m or j2 < 0 or j2 >= m) {
            return -oo;
        }
        
        if (i + 1 == n) {
            if (j1 == j2) {
                return grid[i][j1];
            } else {
                return grid[i][j1] + grid[i][j2];
            }
        }
        
        if (cache[i][j1][j2] != -1) {
            return cache[i][j1][j2];
        }
        
        int robot_1 = grid[i][j1];
        int robot_2 = grid[i][j2];
        
        int cherries_picked = 0;
        
        if (j1 == j2) {
            cherries_picked = robot_1;
        } else {
            cherries_picked = robot_1 + robot_2;
        }
        
        int best_cherries_ahead = 0;
            
        for (int d1 = -1; d1 <= 1; ++d1) {
            for (int d2 = -1; d2 <= 1; ++d2) {
                int cur_candidate = helper(grid, i + 1, j1 + d1, j2 + d2);
                best_cherries_ahead = max(best_cherries_ahead, cur_candidate);
            }
        }
        
        return cache[i][j1][j2] = cherries_picked + best_cherries_ahead;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = int(grid.size());
        int m = int(grid[0].size());
        memset(cache, -1, 71 * 71 * 71 * sizeof(int));
        return helper(grid, 0, 0, m - 1);
    }
};