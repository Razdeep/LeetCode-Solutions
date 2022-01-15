// https://leetcode.com/problems/push-dominoes/

class Solution {
    
    constexpr static int INF = int(1e9) + 1337;
    
public:
    
    string pushDominoes(string dominoes) {
        int n = int(dominoes.size());
        vector<int> left_l(n, -INF), left_r(n, -INF);
        vector<int> right_l(n, INF), right_r(n, INF);
        
        int last_l, last_r;
        last_l = last_r = -INF;
        
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == 'L') {
                last_l = i;
            } else if (dominoes[i] == 'R') {
                last_r = i;
            } else {
                left_l[i] = last_l;
                left_r[i] = last_r;
            }
        }
        
        last_l = last_r = INF;
        
        for (int i = n - 1; i >= 0; --i) {
            if (dominoes[i] == 'L') {
                last_l = i;
            } else if (dominoes[i] == 'R') {
                last_r = i;
            } else {
                right_l[i] = last_l;
                right_r[i] = last_r;
            }
        }
        
        string ans = dominoes;

        for (int i = 0; i < n; ++i) {
            if (ans[i] == '.') {
                int left_r_distance = left_r[i] == -INF || left_l[i] > left_r[i] ? INF : i - left_r[i];
                int right_l_distance = right_l[i] == INF || right_r[i] < right_l[i] ? INF : right_l[i] - i;
                if (left_r_distance == right_l_distance) {
                    
                } else if (left_r_distance < right_l_distance) {
                    ans[i] = 'R';
                } else if (right_l[i] < right_r[i]) {
                    ans[i] = 'L';
                }
            }
        }
        
        return ans;
    }
};