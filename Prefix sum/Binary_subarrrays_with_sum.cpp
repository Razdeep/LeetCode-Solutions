// https://leetcode.com/problems/binary-subarrays-with-sum/submissions/
class Solution {

    static constexpr int MAX = 3 * static_cast<int>(1e4);

    int solveForEdgeCase(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());

        int streak = 0, ans = 0;

        for (int i = 0; i < n; ++i) {
            if (0 == nums[i]) {
                streak++;
            } else {
                ans += (streak * (streak + 1)) / 2;
                streak = 0;
            }
        }

        if (streak) {
            ans += (streak * (streak + 1)) / 2;
        }

        return ans;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        int left = 0, right = 0;
        const int n = static_cast<int>(nums.size());

        int ans = 0;

        int zeros_left[MAX] = {0}, zeros_right[MAX] = {0};
        int prefix_sum[MAX] = {0};

        prefix_sum[0] = nums[0];

        if (0 == goal) {
            return solveForEdgeCase(nums);
        }

        zeros_left[0] = nums[0] == 0;

        for (int i = 1; i < n; ++i) {
            zeros_left[i] = nums[i] == 0 ? zeros_left[i - 1] + 1 : 0;
            prefix_sum[i] = nums[i] + prefix_sum[i - 1];
        }

        zeros_right[n - 1] = nums[n - 1] == 0;

        for (int i = n - 2; i >= 0; --i) {
            zeros_right[i] = nums[i] == 0 ? zeros_right[i + 1] + 1 : 0;
        }

        while (left < n and nums[left] == 0) {
            ++left;
        }

        right = left + 1;

        while (left < n) {

            right = left + 1;

            if (right >= n) {
                break;
            }

            int cur_sum = prefix_sum[right] - (left - 1 >= 0 ? prefix_sum[left - 1] : 0);

            while (cur_sum < goal and right < n) {
                cur_sum = prefix_sum[right] - (left - 1 >= 0 ? prefix_sum[left - 1] : 0);
                ++right;
            }
            --right;

            int cnt_zero_left = left - 1 >= 0 ? zeros_left[left - 1] : 0;
            int cnt_zero_right = right + 1 < n ? zeros_right[right + 1] : 0;

            int contri = 1 + cnt_zero_left + cnt_zero_right + (cnt_zero_left * cnt_zero_right);
            
            if (cur_sum == goal) {
                ans += contri;
            }
        
            ++left;

            while (left < n and nums[left] == 0) {
                ++left;
            }

        }

        return ans;
    }
};