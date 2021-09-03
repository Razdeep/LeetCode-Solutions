class Solution {
public:
    int numSplits(string s) {
        int ans = 0;
        int n = int(s.size());
        
        vector<int> unique_count_from_start(n, 0);
        vector<int> unique_count_from_end(n, 0);
        
        set<char> myset;
        
        for (int i = 0; i < n; ++i) {
            myset.insert(s[i]);
            unique_count_from_start[i] = myset.size();
        }
        
        myset.clear();
        
        for (int i = n - 1; i >= 0; --i) {
            myset.insert(s[i]);
            unique_count_from_end[i] = myset.size();
        }
        
        for (int i = 0; i + 1 < n; ++i) {
            ans += unique_count_from_start[i] == unique_count_from_end[i + 1];
        }
        
        return ans;
    }
};