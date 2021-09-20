// https://leetcode.com/problems/palindromic-substrings/
class Solution {
public:
    bool isPalindrome(string text) {
        int n = int(text.size());
        
        for (int i = 0; 2 * i <= n; ++i) {
            if (text[i] != text[n - i - 1]) {
                return false;
            }
        }
        
        return true;
    }
    
    int countSubstrings(string s) {
        set<pair<int, int> > validPalindromes;
        int n = int(s.size());
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if ((validPalindromes.find(make_pair(i + 1, j - 1)) != validPalindromes.end()) && (s[i] == s[j])) {
                    validPalindromes.insert(make_pair(i, j));
                    ans++;
                } else if (isPalindrome(s.substr(i, j - i + 1))) {
                    validPalindromes.insert(make_pair(i, j));
                    ans++;
                }
            }
        }
        
        return ans;
    }
};