class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = int(rating.size());
        int ans = 0;
        
        for (int i = 1; i + 1 < n; ++i) {
            int prefix_smaller = 0;
            int prefix_bigger = 0;
            for (int j = 0; j < i; ++j) {
                prefix_smaller += rating[j] < rating[i];
                prefix_bigger += rating[j] > rating[i];
            }
            
            int suffix_smaller = 0;
            int suffix_bigger = 0;
            for (int j = i + 1; j < n; ++j) {
                suffix_smaller += rating[j] < rating[i];
                suffix_bigger += rating[j] > rating[i];
            }
            
            ans += (prefix_smaller * suffix_bigger) + (prefix_bigger * suffix_smaller);
        }
        
        return ans;
    }
};