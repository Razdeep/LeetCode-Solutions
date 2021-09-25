// https://leetcode.com/problems/beautiful-arrangement/
class Solution {
    void calculate(int pos, int n, vector<bool>& visited, int &count) {
        if (pos > n) {
            count++;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && ((i % pos == 0) || (pos % i == 0))) {
                visited[i] = true;
                calculate(pos + 1, n, visited, count);
                visited[i] = false;
            }
        }
    }
public:
    int countArrangement(int n) {
        int count = 0;
        vector<bool> visited(n + 1, false);
        calculate(1, n, visited, count);
        
        return count;
    }
};