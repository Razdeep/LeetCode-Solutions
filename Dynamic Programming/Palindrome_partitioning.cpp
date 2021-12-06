// https://leetcode.com/problems/palindrome-partitioning/
class Solution {
public:    
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> partitions;
        int n = int(s.size());
        
        helper(s, partitions, ans);
        return ans;
    }
    
    void helper(string text, vector<string>& partitions, vector<vector<string> >& ans) {
        int n = int(text.size());
        if (text == "") {
            ans.push_back(partitions);
            return;
        }
        
        for (int i = 0; i < n; ++i) {
            if (isPalindrome(text.substr(0, i + 1))) {
                partitions.push_back(text.substr(0, i + 1));
                helper(text.substr(i + 1), partitions, ans);
                partitions.pop_back();
            }
        }
        return;
    }
    
    bool isPalindrome(string text) {
        int n = int(text.size());
        
        for (int i = 0; 2 * i < n; ++i) {
            if (text[i] != text[n - i - 1]) {
                return false;
            }
        }
        
        return true;
    }
};