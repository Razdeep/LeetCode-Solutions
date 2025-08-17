// https://leetcode.com/problems/report-spam-message/description/

class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        int match = 0;
        set<string> st;
        for (const auto& banned_word: bannedWords) {
            st.insert(banned_word);
        }

        for (const auto& msg: message) {
            match += (st.find(msg) != st.end());
        }

        return match >= 2;
    }
};