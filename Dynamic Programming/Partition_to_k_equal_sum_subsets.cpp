// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/
#pragma GCC optimize ("O3")
class Solution {
    bool visited[20] = {false};
    short arr[20];
    char n;
    short target;
public:
    inline bool helper(short k_sub, short idx, short cur_sum) {
        
        if (k_sub == 0) {
            return true;
        }
        
        bool res = false;
        
        if (cur_sum == target) {
            res |= helper(k_sub - 1, 0, 0);
        }
       
        for (char i = idx; i < n; ++i) {
            if (!visited[i]) {
                visited[i] = true;
                if (cur_sum + arr[i] <= target) {
                    res |= helper(k_sub, i + 1, cur_sum + arr[i]);
                }
                visited[i] = false;
            }
            if (res) {
                return true;
            }
        }

        return res;
    }
    
    inline bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.rbegin(), nums.rend());
        n = int(nums.size());
        for (int i = 0; i < n; ++i) {
            arr[i] = nums[i];
        }
        
        if (sum % k) {
            return false;
        }
        target = sum / k;
        
        return helper(k, 0, 0);
    }
};