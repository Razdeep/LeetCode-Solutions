// https://leetcode.com/problems/is-subsequence/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = int(s.size());
        int n2 = int(t.size());
        if (n1 == 0) {
            return true;
        }
        if (n2 == 0) {
            return false;
        }
        
        int i = 0;
        
        for (int j = 0; j < n2; ++j) {
            if (s[i] == t[j]) {
                i++;
            }
        }
        
        return i == n1;
    }
};