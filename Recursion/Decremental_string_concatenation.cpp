// https://leetcode.com/problems/decremental-string-concatenation/description/
class Solution {
public:
    int dp[1001][26][26];

    int dfs(int index, int first_char, int last_char, vector<string>& words) {
        int n = static_cast<int>(words.size());

        if (index == n) {
            return 0;
        }

        if (-1 != dp[index][first_char][last_char]) {
            return dp[index][first_char][last_char];
        }

        int case_1 = 0, case_2 = 0;

        case_1 = case_2 = static_cast<int>(words[index].size());;

        case_1 += dfs(index + 1, first_char, words[index].back() - 'a', words);
        case_2 += dfs(index + 1, words[index][0] - 'a', last_char, words);

        if (last_char == words[index][0] - 'a') {
            --case_1;
        }
        if (first_char == words[index].back() - 'a') {
            --case_2;
        }
        
        return dp[index][first_char][last_char] = min(case_1, case_2);
    }

    int minimizeConcatenatedLength(vector<string>& words) {
        memset(dp, -1, 1001 * 26 * 26 * sizeof(int));
        return words[0].size() + dfs(1, words[0][0] - 'a', words[0].back() - 'a', words);
    }
};