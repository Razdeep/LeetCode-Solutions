// https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
class Solution {
    static constexpr int MOD = int(1e9) + 7;
    vector<vector<int> > cache;
public:
    int helper(int dice_count, int face_count, int target) {
        if (target < 0) {
            return 0;
        }
        if (dice_count < 0) {
            return 0;
        }
        if (dice_count == 0 and target == 0) {
            return 1;
        }
        if (cache[dice_count][target] != -1) {
            return cache[dice_count][target];
        }
        
        long long ans = 0;
        
        for (int face = 1; face <= face_count; ++face) {
            ans += helper(dice_count - 1, face_count, target - face) % MOD;
        }
        
        return cache[dice_count][target] = ans % MOD;
    }
    
    int numRollsToTarget(int dice_count, int face_count, int target) {
        cache.resize(dice_count + 1, vector<int>(target + 1, -1));
        return helper(dice_count, face_count, target);
    }
};