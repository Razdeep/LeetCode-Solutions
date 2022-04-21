// https://leetcode.com/problems/find-good-days-to-rob-the-bank/
class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = int(security.size());
        vector<int> ans;
        vector<int> downhill_count(n, 0), uphill_count(n, 0);
        
        for (int i = 1; i < n; ++i) {
            if (security[i] <= security[i - 1])  {
                downhill_count[i] = 1 + downhill_count[i - 1];
            }
        }
        
        for (int i = n - 2; i >= 0; --i) {
            if (security[i + 1] >= security[i]) {
                uphill_count[i] = 1 + uphill_count[i + 1];
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (uphill_count[i] >= time and downhill_count[i] >= time) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};