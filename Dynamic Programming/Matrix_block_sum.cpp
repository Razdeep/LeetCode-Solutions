// https://leetcode.com/problems/matrix-block-sum/

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        
        int no_of_rows = mat.size();
        int no_of_cols = mat[0].size();

        if (no_of_rows <= 1 || no_of_cols <= 1) {
            return mat;
        }

        vector<vector<int> > cumSum(no_of_rows + 1, vector<int> (no_of_cols + 1, 0));
        
        cumSum[0][0] = mat[0][0];
        
        for (int i = 1; i < no_of_cols; ++i) {
            cumSum[0][i] = cumSum[0][i - 1] + mat[0][i];
        }
        
        for (int i = 1; i < no_of_rows; ++i) {
            cumSum[i][0] = cumSum[i - 1][0] + mat[i][0];
        }
        
        for (int i = 1; i < no_of_rows; ++i) {
            for (int j = 1; j < no_of_cols; ++j) {
                cumSum[i][j] = mat[i][j] + cumSum[i - 1][j] + cumSum[i][j - 1] - cumSum[i - 1][j - 1];
            }
        }
        
        vector<vector<int> > ans(no_of_rows, vector<int> (no_of_cols, 0));
        
        for (int i = 0; i < no_of_rows; ++i) {
            for (int j = 0; j < no_of_cols; ++j) {
                int bottom_right = cumSum[min(i + k, int(no_of_rows) - 1) ] [min(j + k, int(no_of_cols) - 1)];
                
                int top_right = i - k - 1 >= 0 ? cumSum[i - k - 1] [min(j + k, int(no_of_cols) - 1)] : 0;
                
                int bottom_left = j - k - 1 >= 0 ? cumSum[min(i + k, int(no_of_rows) - 1)] [j - k - 1] : 0;                 

                int top_left = i - k - 1 >= 0 && j - k - 1 >= 0 ? cumSum[i - k - 1] [j - k - 1] : 0;                              

                ans[i][j] = bottom_right - top_right - bottom_left + top_left;
            }
        }
        return ans;
    }
};