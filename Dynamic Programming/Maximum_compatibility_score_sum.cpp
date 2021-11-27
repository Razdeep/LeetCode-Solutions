// https://leetcode.com/problems/maximum-compatibility-score-sum/

class Solution {
public:
    
    int calcScore(vector<int>& student, vector<int>& mentor) {
        int n = min(int(mentor.size()), int(student.size()));
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += (student[i] == mentor[i]);
        }
        return res;
    }
    
    int helper(vector<vector<int> >& students, vector<vector<int> >& mentors, vector<int>& visited, int pos, int score) {
        int n = int(students.size());
        int res = 0;
        
        if (pos >= n) {
            return score;
        }
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                visited[i] = true;
                res = max(res, helper(students, mentors, visited, pos + 1, score + calcScore(students[pos], mentors[i])));
                visited[i] = false;
            }
        }
        return res;
    }
    
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        int n = int(students.size());
        vector<int> visited(n, false);
        return helper(students, mentors, visited, 0, 0);
    }
    
};