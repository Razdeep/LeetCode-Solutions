// https://leetcode.com/problems/count-substrings-that-differ-by-one-character/
class Solution {
public:
    int match(const string &s, const string &t) {
        int res = 0;
        for (int i = 0; i + s.size() - 1 < t.size(); ++i) {
            int j = 0;
            int mismatch = 0;
            while (j < s.size()) {
                mismatch += t[i + j] != s[j];
                ++j;
            }
            res += mismatch == 1;
        }
        return res;
    }
    
    int countSubstrings(string s, string t) {
        int n = int(s.size());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                string sub = "";
                for (int k = i; k <= j; ++k) {
                    sub.push_back(s[k]);
                }
                ans += match(sub, t);
            }
        }
        return ans;
    }
};