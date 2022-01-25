// https://leetcode.com/problems/knight-probability-in-chessboard/
class Solution {
public:
    int isValid(int x, int y, int n) {
        return (x >= 0) and (x < n) and (y >= 0) and (y < n);
    }
    
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double> > present(n, vector<double>(n, 0.0));
        present[row][column] = 1.0;
        
        for (int pass = 0; pass < k; ++pass) {
            vector<vector<double> > future(n, vector<double>(n, 0.0));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (present[i][j] != 0) {
                        
                        int ni = i - 1, nj = j - 2;
                        if (isValid(ni, nj, n)) {
                            future[ni][nj] += (present[i][j] / 8.0);
                        }
                        
                        ni = i - 2, nj = j - 1;
                        if (isValid(ni, nj, n)) {
                            future[ni][nj] += (present[i][j] / 8.0);
                        }
                        
                        ni = i - 2, nj = j + 1;
                        if (isValid(ni, nj, n)) {
                            future[ni][nj] += (present[i][j] / 8.0);
                        }
                        
                        ni = i - 1, nj = j + 2;
                        if (isValid(ni, nj, n)) {
                            future[ni][nj] += (present[i][j] / 8.0);
                        }
                        
                        ni = i + 1, nj = j + 2;
                        if (isValid(ni, nj, n)) {
                            future[ni][nj] += (present[i][j] / 8.0);
                        }
                        
                        ni = i + 2, nj = j + 1;
                        if (isValid(ni, nj, n)) {
                            future[ni][nj] += (present[i][j] / 8.0);
                        }
                        
                        ni = i + 2, nj = j - 1;
                        if (isValid(ni, nj, n)) {
                            future[ni][nj] += (present[i][j] / 8.0);
                        }
                        
                        ni = i + 1, nj = j - 2;
                        if (isValid(ni, nj, n)) {
                            future[ni][nj] += (present[i][j] / 8.0);
                        }
                    }
                }                
            }
            
            present = future;
        }
        
        double ans = 0.0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                ans += present[i][j];
            }
        }
        
        return ans;
    }
};