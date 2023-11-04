// https://leetcode.com/contest/weekly-contest-369/problems/minimum-equal-sum-of-two-arrays-after-replacing-zeros/
class Solution {
public:
    long long minSum(vector<int>& a, vector<int>& b) {
        
        int zeros_in_a = 0, zeros_in_b = 0;
        long long sum_a = 0, sum_b = 0;
        
        for (int it: a) {
            sum_a += it;
            zeros_in_a += it == 0;
        }
        
        for (int it: b) {
            sum_b += it;
            zeros_in_b += it == 0;
        }
        
        if (sum_a == sum_b) {
            if ((0 == zeros_in_a) and (0 == zeros_in_b)) {
                return sum_a;
            }
        }
        
        if (0 == zeros_in_a) {
            if (sum_b + zeros_in_b > sum_a) {
                return -1;
            }
        }
        
        if (0 == zeros_in_b) {
            if (sum_a + zeros_in_a > sum_b) {
                return -1;
            }
        }
        
        return max(sum_a + zeros_in_a, sum_b + zeros_in_b);
    }
};