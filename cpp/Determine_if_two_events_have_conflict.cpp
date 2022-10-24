// https://leetcode.com/contest/weekly-contest-316/problems/determine-if-two-events-have-conflict/

class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int time_1 = stoi(event1[0].substr(0, 2) + event1[0].substr(3, 2));
        int time_2 = stoi(event1[1].substr(0, 2) + event1[1].substr(3, 2));
        int time_3 = stoi(event2[0].substr(0, 2) + event2[0].substr(3, 2));
        int time_4 = stoi(event2[1].substr(0, 2) + event2[1].substr(3, 2));
        return (time_1 >= time_3 and time_1 <= time_4)
            or (time_2 >= time_3 and time_2 <= time_4)
            or (time_3 >= time_1 and time_3 <= time_2)
            or (time_4 >= time_1 and time_4 <= time_2);
    }
};