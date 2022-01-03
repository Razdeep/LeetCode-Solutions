// https://leetcode.com/problems/vowels-of-all-substrings/

class Solution {
    const string vowels = "aeiou";
public:
    auto isVowel(const char& c) {
        return vowels.find(c) != string::npos;
    }
    
    long long countVowels(string word) {
        long long ans = 0;
        int n = int(word.size());
        
        for (long long i = 0; i < int(word.size()); ++i) {
            if (isVowel(word[i])) {
                long long left_side = (i + 1);
                long long right_side = (n - i);
                ans += (left_side * right_side);
            }
        }
        
        return ans;
    }
};