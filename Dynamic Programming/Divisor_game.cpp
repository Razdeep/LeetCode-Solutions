// https://leetcode.com/problems/divisor-game/

class Solution {
public:
    vector<int> cache;
    bool divisorGame(int N) {
        
        cache.resize(max(2, N + 1), -1);
        cache[0] = true;
        cache[1] = false;
        
        int res = helper(N);
        return res;
    }
    
    bool helper(int n) {
        
        if (cache[n] != -1) {
            return cache[n];
        }
        
        cache[n] = false;

        for (int i = 1; i * i <= n; ++i) {
            if (n % i == 0) {
                int factor_1 = i;
                int factor_2 = n / i;
                
                if (!helper(n - factor_1) || !helper(n - factor_2)) {
                    cache[n] = true;
                    return true;
                }
            }
        }
        
        return cache[n];
    }
};