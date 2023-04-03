// https://leetcode.com/problems/remove-duplicate-letters/description/
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = static_cast<int>(s.size());
        vector<int> characters_left(26, 0);

        for (int i = 0; i < n; ++i) {
            characters_left[s[i] - 'a']++;
        }

        stack<char> st;
        vector<bool> visited(26, false);

        for (int i = 0; i < n; ++i) {
            if (st.empty()) {
                st.push(s[i]);
                characters_left[s[i] - 'a']--;
                visited[s[i] - 'a'] = true;
                continue;
            }

            if (visited[s[i] - 'a']) {
                continue;
            }

            char top_char = st.top();
            while (!st.empty() and s[i] < top_char and characters_left[top_char - 'a'] >= 1) {
                visited[top_char - 'a'] = false;
                st.pop();
                if (st.empty()) {
                    break;
                }
                top_char = st.top();
            }

            st.push(s[i]);
            visited[s[i] - 'a'] = true;
            characters_left[s[i] - 'a']--;
        }

        string ans = "";
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main() {
    Solution solution;
    // solution.removeDuplicateLetters("ecbacba");
    solution.removeDuplicateLetters("bbcaac");
    return 0;
}