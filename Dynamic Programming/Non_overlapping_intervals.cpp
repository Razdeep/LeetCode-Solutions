// https://leetcode.com/problems/non-overlapping-intervals/
class Solution {
    static constexpr int oo = int(1e9);
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Surprisingly, greedy works here
        // dp also gives correct answer but causing TLE
        // due to high time complexity
        
        int n = int(intervals.size());
        enum TimeStamp { STARTING, ENDING };
        
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int> &b) {
           return a[ENDING] < b[ENDING];
        });
        
        int non_overlapping_interval_count = 0;
        int current_ending = -oo;
        
        for (const auto& interval: intervals) {
            if (interval[STARTING] >= current_ending) {
                ++non_overlapping_interval_count;
                current_ending = interval[ENDING];
            }
        }
        
        return n - non_overlapping_interval_count;
    }
};