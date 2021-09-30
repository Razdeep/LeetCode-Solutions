// https://leetcode.com/problems/arithmetic-slices/
class Solution {
    #define trace(x) cout << x << ": " << x << endl;
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = int(nums.size());
        int ans = 0;
        if (nums.size() == 1) {
            return 0;
        }
        int cur_diff = nums[1] - nums[0];
        int streak = 1;
        for (int i = 2; i < n; ++i) {
            if (nums[i] - nums[i - 1] == cur_diff) {
                streak++;
            } else {
                ans += ((streak * (streak + 1) / 2) - streak);
                streak = 1;
            }
            cur_diff = nums[i] - nums[i - 1];
        }
        if (streak > 1) {
            ans += ((streak * (streak + 1) / 2) - streak);
        }
        return ans;
    }
};