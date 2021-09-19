class Solution {
public:

    int oo = int(1e9);
    vector<vector<int> > dp;
    
    int calcMinCost(const vector<int>& arr, int i, int j) {
        
        if (dp[i][j] != oo) {
            return dp[i][j];
        }
        
        if (i == j) {
            return 0;
        }
        
        for (int k = i; k < j; ++k) {
            int max_left = -oo, max_right = -oo;
            for (int p = i; p <= k; ++p) {
                max_left = max(max_left, arr[p]);
            }
            for (int p = k + 1; p <= j; ++p) {
                max_right = max(max_right, arr[p]);
            }
            int this_ans = calcMinCost(arr, i, k) + calcMinCost(arr, k + 1, j) + (max_left * max_right);
                
            dp[i][j] = min(dp[i][j], this_ans);
        }
        
        return dp[i][j];
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = int(arr.size());
        dp.resize(n, vector<int>(n, oo));
        
        return calcMinCost(arr, 0, n - 1);
    }
};