class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int no_of_rows = int(matrix.size());
        int no_of_cols = int(matrix[0].size());
        
        vector<vector<int> > maxOrder(no_of_rows, vector<int>(no_of_cols, 0));
        
        int total_squares = 0;
        
        for (int i = 0; i < no_of_rows; ++i) {
            for (int j = 0; j < no_of_cols; ++j) {
                
                if (i == 0 || j == 0) {
                    maxOrder[i][j] = matrix[i][j];
                    total_squares += maxOrder[i][j];
                    continue;
                }
                
                if (matrix[i][j]) {
                    maxOrder[i][j] = 1;
                    maxOrder[i][j] = 1 + min({maxOrder[i - 1][j], 
                                              maxOrder[i][j - 1], 
                                              maxOrder[i - 1][j - 1]});
                    total_squares += maxOrder[i][j];
                }
            }
        }
        
        return total_squares;
    }
};