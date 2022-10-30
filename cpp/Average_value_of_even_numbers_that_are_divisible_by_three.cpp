// https://leetcode.com/contest/weekly-contest-317/problems/average-value-of-even-numbers-that-are-divisible-by-three/
class Solution {
public:
    int averageValue(vector<int>& nums) {
        int sum = 0, cnt = 0;
        for (int num: nums) {
            if (num % 3 == 0 and num % 2 == 0) {
                sum += num;
                cnt++;
            }
        }
        
        return cnt == 0 ? 0 : sum / cnt;
    }
};