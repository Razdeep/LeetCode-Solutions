// https://leetcode.com/problems/video-stitching/
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), [](auto a, auto b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        
        enum TimeStamp { STARTING, ENDING };
        int i = 0;
        int n = int(clips.size());
        int cur_end = 0;
        int next_end = 0;
        int ans = 0;
        
        while (i < n and next_end < time) {
            while (i < n and clips[i][STARTING] <= cur_end) {
                next_end = max(next_end, clips[i][ENDING]);
                ++i;
            }
            if (cur_end == next_end) {
                break;
            }
            cur_end = next_end;
            ans++;
        }
        
        if (next_end < time) {
            return -1;
        }
        
        return ans;
    }
};