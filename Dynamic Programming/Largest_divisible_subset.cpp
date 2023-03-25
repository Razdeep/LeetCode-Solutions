// https://leetcode.com/problems/largest-divisible-subset/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = int(nums.size());
        vector<int> largest_chain(n, 1);
        vector<int> previous_elem(n, -1);

        largest_chain[0] = 1;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int cur_predecessor = j;
                int red_flag = false;
                while (cur_predecessor != -1) {
                    if (nums[i] % nums[cur_predecessor] != 0 and \
                            nums[cur_predecessor] % nums[i] != 0) {
                        red_flag = true;
                    }
                    cur_predecessor = previous_elem[cur_predecessor];
                }
                if (!red_flag and largest_chain[j] + 1 > largest_chain[i]) {
                    largest_chain[i] = largest_chain[j] + 1;
                    previous_elem[i] = j;
                }
            }
        }

        int max_idx = -1;
        int max_so_far = -1;

        for (int i = 0; i < n; ++i) {
            cout << largest_chain[i] << " ";
            if (max_so_far < largest_chain[i]) {
                max_so_far = largest_chain[i];
                max_idx = i;
            }
        }

        int idx = max_idx;
        
        vector<int> res;

        while (idx != -1) {
            res.push_back(nums[idx]);
            idx = previous_elem[idx];
        }

        reverse(res.begin(), res.end());

        return res;
        
    }
};