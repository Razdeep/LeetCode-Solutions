class Solution {
    #define trace(x) cout << #x << ": " << x << endl;
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int oo = int(1e9);
        int n = int(books.size());
        vector<int> dp(n, 0);
        
        int current_width = 0;
        const int WIDTH = 0;
        const int HEIGHT = 1;
        dp[0] = books[0][HEIGHT];
        
        for (int i = 1; i < n; ++i) {
            dp[i] = dp[i - 1] + books[i][HEIGHT];
            current_width = books[i][WIDTH];
            int max_height_in_bottom_shelf = books[i][HEIGHT];
            
            for (int j = i - 1; j >= 0 && (books[j][WIDTH] + current_width <= shelfWidth); --j) {
                max_height_in_bottom_shelf = max(max_height_in_bottom_shelf, books[j][HEIGHT]);
                dp[i] = min(dp[i], (j - 1 >= 0 ? dp[j - 1] : 0) + max_height_in_bottom_shelf);
                current_width += books[j][WIDTH];
            }
        }
        return dp[n - 1];
    }
};