// https://leetcode.com/problems/largest-plus-sign/
class Solution {
   public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));
        int ans = 0;

        for (int i = 0; i < int(mines.size()); ++i) {
            grid[mines[i][0]][mines[i][1]] = 0;
        }

        vector<vector<int>> up_ones(n, vector<int>(n, 0));
        vector<vector<int>> down_ones(n, vector<int>(n, 0));
        vector<vector<int>> left_ones(n, vector<int>(n, 0));
        vector<vector<int>> right_ones(n, vector<int>(n, 0));

        // initializing
        for (int i = 0; i < n; ++i) {
            up_ones[0][i] = grid[0][i];
            down_ones[n - 1][i] = grid[n - 1][i];
            left_ones[i][0] = grid[i][0];
            right_ones[i][n - 1] = grid[i][n - 1];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                up_ones[i][j] = grid[i][j] == 0 ? 0 : 1 + up_ones[i - 1][j];
                left_ones[j][i] = grid[j][i] == 0 ? 0 : 1 + left_ones[j][i - 1];
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < n; ++j) {
                down_ones[i][j] = grid[i][j] == 0 ? 0 : 1 + down_ones[i + 1][j];
                right_ones[j][i] =
                    grid[j][i] == 0 ? 0 : 1 + right_ones[j][i + 1];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans = max(ans, min({up_ones[i][j], down_ones[i][j],
                                    left_ones[i][j], right_ones[i][j]}));
            }
        }

        return ans;
    }
};