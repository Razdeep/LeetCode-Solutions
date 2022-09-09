// https://leetcode.com/problems/construct-smallest-number-from-di-string/
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = int(pattern.size());
        stack<int> st;
        st.push(1);
        
        string ans = "";
        
        for (int i = 0; i <= n; ++i) {
            if (pattern[i] == 'I' or i == n) {
                while (not st.empty()) {
                    ans.push_back('0' + st.top());
                    st.pop();
                }
            }
            st.push(i + 2);
        }
        
        return ans;
    }
};