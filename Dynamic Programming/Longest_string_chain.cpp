// https://leetcode.com/problems/longest-string-chain/
class Solution {
public:
    static bool byMethod(string a, string b) {
        return a.size() < b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), byMethod);
        map<string, int> longest_string_chain;
        
        for (string word: words) {
            longest_string_chain[word] = 1;
        }
        
        int ans = 1;
        
        for (string word: words) {
            for (int i = 0; i < int(word.size()); ++i) {
                string new_word = word.substr(0, i) + word.substr(i + 1);
                if (longest_string_chain.find(new_word) != longest_string_chain.end()) {
                    longest_string_chain[word] = max(longest_string_chain[word], longest_string_chain[new_word] + 1);
                    ans = max(ans, longest_string_chain[word]);
                }
            }
        }
        
        return ans;
    }
};