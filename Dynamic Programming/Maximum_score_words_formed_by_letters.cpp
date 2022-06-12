// https://leetcode.com/problems/maximum-score-words-formed-by-letters/
class Solution {
public:
    int solve(vector<string>& words, vector<int> letters_freq, vector<int>& score, int idx) {
        
        int n = int(words.size());
        if (idx >= n) {
            return 0;
        }
        
        // ignoring current word
        int ans = solve(words, letters_freq, score, idx + 1);
        auto updated_letters_freq = letters_freq;
        
        bool ok_to_include = true;
        int potential_score = 0;
        string word = words[idx];
        for (int i = 0; i < int(word.size()); ++i) {
            if (updated_letters_freq[word[i] - 'a'] > 0) {
                updated_letters_freq[word[i] - 'a']--;
                potential_score += score[word[i] - 'a'];
            } else {
                ok_to_include = false;
            }
        }
        
        if (ok_to_include) {
            ans = max(ans, potential_score + solve(words, updated_letters_freq, score, idx + 1));
        }
        
        return ans;
        
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> letter_freq(26, 0);
        
        for (auto& ch: letters) {
            letter_freq[ch - 'a']++;
        }
        
        return solve(words, letter_freq, score, 0);
    }
};