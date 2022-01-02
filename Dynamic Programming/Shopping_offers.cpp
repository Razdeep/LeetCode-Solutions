// https://leetcode.com/problems/shopping-offers/

class Solution {

public:
    int helper(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int min_total_so_far = 0;
        int n = int(price.size());
        
        // Firstly not using any special offer
        for (int i = 0; i < n; ++i) {
            min_total_so_far += price[i] * needs[i];
        }
        
        // Ignoring the last element of special because it contains the offer price and not the item count
        for (int i = 0; i < int(special.size()); ++i) {
            vector<int> new_needs;
            bool is_this_offer_applicable = true;
            for (int j = 0; j + 1 < int(special[i].size()); ++j) {
                new_needs.push_back(needs[j] - special[i][j]);
                if (new_needs.back() < 0) {
                    is_this_offer_applicable = false;
                    break;
                }
            }
            if (is_this_offer_applicable) {
                min_total_so_far = min(min_total_so_far, special[i].back() + helper(price, special, new_needs));
            }
        }
        
        return min_total_so_far;
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return helper(price, special, needs);
    }
};