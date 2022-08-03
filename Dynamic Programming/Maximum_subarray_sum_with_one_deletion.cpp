// https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion/
class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = int(arr.size());
        vector<int> kadane_forward(n, 0);
        
        kadane_forward[0] = arr[0];
        
        for (int i = 1; i < n; ++i) {
            int candidate = arr[i] + kadane_forward[i - 1];
            kadane_forward[i] = max(candidate, arr[i]);
        }
        
        vector<int> kadane_backward(n, 0);
        kadane_backward[n - 1] = arr.back();
        
        for (int i = n - 2; i >= 0; --i) {
            int candidate = arr[i] + kadane_backward[i + 1];
            kadane_backward[i] = max(candidate, arr[i]);
        }
        
        int ans = *std::max_element(kadane_forward.begin(),
                                    kadane_forward.end());
        
        for (int i = 0; i + 2 < n; ++i) {
            ans = max(ans, kadane_forward[i] + kadane_backward[i + 2]);
        }
        
        return ans;
    }
};