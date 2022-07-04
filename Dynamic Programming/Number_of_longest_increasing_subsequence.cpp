// https://leetcode.com/problems/number-of-longest-increasing-subsequence/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = int(nums.size());
        vector<int> lis(n, 1);
        vector<int> no_of_lis(n, 1);
        bool all_same = true;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    all_same = false;
                    if (lis[i] < lis[j] + 1) {
                        lis[i] = lis[j] + 1;
                        no_of_lis[i] = no_of_lis[j];
                    } else if (lis[i] == lis[j] + 1) {
                        no_of_lis[i] += no_of_lis[j];
                    }
                }
            } 
        }
                
        int res = 0;
        int max_lis_so_far = 0;
        
        for (int i = 0; i < n; ++i) {
            if (lis[i] > max_lis_so_far) {
                max_lis_so_far = lis[i];
                res = no_of_lis[i];
            } else if (lis[i] == max_lis_so_far) {
                res += no_of_lis[i];
            }
        }
        
        return all_same ? nums.size() : res;
    }
};