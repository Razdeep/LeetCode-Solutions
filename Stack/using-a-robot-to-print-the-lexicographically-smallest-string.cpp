// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/

class Solution {
public:

    string robotWithString(string s) {

        vector<int> freq(26, 0);

        for (int i = 0; i < s.size(); ++i) {
            freq[s[i] - 'a']++;
        }

        char min_char_undiscovered = 'a';
        stack<char> st;
        string ans = "";

        for (int i = 0; i < s.size(); ++i) {
            st.push(s[i]);
            freq[s[i] - 'a']--;

            while (min_char_undiscovered <= 'z' && freq[min_char_undiscovered - 'a'] == 0) {
                min_char_undiscovered++;
            }

            while (!st.empty() && st.top() <= min_char_undiscovered) {
                ans.push_back(st.top());
                st.pop();
            }
        }

        return ans;
    }
};