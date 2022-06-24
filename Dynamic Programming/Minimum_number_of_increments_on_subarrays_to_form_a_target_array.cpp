// https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/
class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = int(target.size());
        int ans = target[0];
        for (int i = 1; i < n; ++i) {
            ans += max(0, target[i] - target[i - 1]);
        }
        return ans;
    }
};