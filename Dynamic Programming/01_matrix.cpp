// https://leetcode.com/problems/01-matrix/
class Solution {
    static constexpr int oo = int(1e9);
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = int(mat.size());
        int m = int(mat[0].size());
        
        // ------------------------------------------------ //
        vector<vector<int> > up_left(n, vector<int>(m, oo));
        
        for (int i = 0; i < n; ++i) {
            if (mat[i][0] == 0) {
                up_left[i][0] = 0;
            } else {
                up_left[i][0] = 1 + (i - 1 >= 0 ? up_left[i - 1][0] : oo - 1);
            }
        }
        
        for (int i = 0; i < m; ++i) {
            if (mat[0][i] == 0) {
                up_left[0][i] = 0;
            } else {
                up_left[0][i] = 1 + (i - 1 >= 0 ? up_left[0][i - 1] : oo - 1);
            }
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                if (mat[i][j]) {
                    up_left[i][j] = 1 + min(up_left[i - 1][j], up_left[i][j - 1]);
                } else {
                    up_left[i][j] = 0;
                }
            }
        }
        // ------------------------------------------------ //
        
        vector<vector<int> > down_right(n, vector<int>(m, oo));
        
        for (int i = n - 1; i >= 0; --i) {
            if (mat[i][m - 1] == 0) {
                down_right[i][m - 1] = 0;
            } else {
                down_right[i][m - 1] = 1 + (i + 1 < n ? down_right[i + 1][m - 1] : oo - 1);
            }
        }
        
        for (int i = m - 1; i >= 0; --i) {
            if (mat[n - 1][i] == 0) {
                down_right[n - 1][i] = 0;
            } else {
                down_right[n - 1][i] = 1 + (i + 1 < m ? down_right[n - 1][i + 1] : oo - 1);
            }
        }
        
        for (int i = n - 2; i >= 0; --i) {
            for (int j = m - 2; j >= 0; --j) {
                if (mat[i][j]) {
                    down_right[i][j] = 1 + min(down_right[i + 1][j], down_right[i][j + 1]);
                } else {
                    down_right[i][j] = 0;
                }
            }
        }
        // ------------------------------------------------ //
        vector<vector<int> > up_right(n, vector<int>(m, oo));
        
        for (int i = 0; i < n; ++i) {
            if (mat[i][m - 1] == 0) {
                up_right[i][m - 1] = 0;
            } else {
                up_right[i][m - 1] = 1 + (i - 1 >= 0 ? up_right[i - 1][m - 1] : oo - 1);
            }
        }
        
        for (int i = m - 1; i >= 0; --i) {
            if (mat[0][i] == 0) {
                up_right[0][i] = 0;
            } else {
                up_right[0][i] = 1 + (i - 1 >= 0 ? up_right[0][i - 1] : oo - 1);
            }
        }
        
        for (int i = 1; i < n; ++i) {
            for (int j = m - 2; j >= 0; --j) {
                if (mat[i][j]) {
                    up_right[i][j] = 1 + min(up_right[i - 1][j], up_right[i][j + 1]);
                } else {
                    up_right[i][j] = 0;
                }
            }
        }
        // ------------------------------------------------ //
        
        vector<vector<int> > down_left(n, vector<int>(m, oo));
        
        for (int i = n - 1; i >= 0; --i) {
            if (mat[i][0] == 0) {
                down_left[i][0] = 0;
            } else {
                down_left[i][0] = 1 + (i + 1 < n ? down_left[i + 1][0] : oo - 1);
            }
        }
        
        for (int i = 0; i < m; ++i) {
            if (mat[n - 1][i] == 0) {
                down_left[n - 1][i] = 0;
            } else {
                down_left[n - 1][i] = 1 + (i - 1 >= 0 ? down_left[n - 1][i - 1] : oo - 1);
            }
        }
        
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 1; j < m; ++j) {
                if (mat[i][j]) {
                    down_left[i][j] = 1 + min(down_left[i + 1][j], down_left[i][j - 1]);
                } else {
                    down_left[i][j] = 0;
                }
            }
        }
        
        // ------------------------------------------------ //
        
        vector<vector<int> > res(n, vector<int>(m, oo));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res[i][j] = min({
                        up_left[i][j], 
                        down_right[i][j],
                        up_right[i][j], 
                        down_left[i][j]
                    });
            }
        }
        
        return res;
    }
};