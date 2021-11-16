// https://leetcode.com/problems/optimal-division/

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string ans = "";
        int n = int(nums.size());
        for (int i = 0; i < n; ++i) {
            if (i > 0) {
                ans += "/";
            }
            if (n > 2 && i == 1) {
                ans += "(";
            }
            ans += to_string(nums[i]);
            if (n > 2 && i + 1 == n) {
                ans += ")";
            }
        }
        
        return ans;
    }
};