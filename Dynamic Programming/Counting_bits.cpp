// https://leetcode.com/problems/counting-bits/
class Solution {
public:
    int countBitsForInt(int x) {
        int res = 0;
        while (x > 0) {
            res += (x & 1);
            x >>= 1;
        }
        return res;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        
        for (int i = 0; i <= n; ++i) {
            ans[i] = countBitsForInt(i);
        }
        
        return ans;
    }
};