// https://leetcode.com/problems/closest-equal-element-queries/
class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        vector<int> ans(queries.size(), 0);

        vector<vector<int> > indices(1e5 + 7, vector<int>());

        for (int i = 0; i < nums.size(); ++i) {
            indices[nums[i]].push_back(i);
        }

        for (int i = 0; i < queries.size(); ++i) {
            int query = queries[i];
            int target = nums[query];

            const vector<int>& sub = indices[target];
            const int sub_size = sub.size();

            if (sub_size == 1) {
                ans[i] = -1;
            } else if (sub_size == 2) {
                ans[i] = min(
                    abs(sub[0] - sub[1]),
                    n - abs(sub[0] - sub[1])
                );
            } else {
                
                const auto& target_itr = lower_bound(sub.begin(), sub.end(), query);

                int lower = target_itr == sub.begin() ? 
                                sub[sub_size - 1] : *(target_itr - 1);

                int higher = target_itr + 1 == sub.end() ? 
                                sub[0] : *(target_itr + 1);

                ans[i] = min({
                    abs(lower - query), 
                    abs(higher - query),
                    n - abs(lower - query), 
                    n - abs(higher - query)
                });
            }
        }

        return ans;
    }
};