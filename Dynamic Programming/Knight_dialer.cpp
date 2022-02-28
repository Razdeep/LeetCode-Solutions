// https://leetcode.com/problems/knight-dialer/
class Solution {
    static constexpr int MOD = int(1e9) + 7;
public:
    int knightDialer(int n) {
        vector<vector<long long> > sourceOf(10, vector<long long>(0));
        sourceOf[0].push_back(4);
        sourceOf[0].push_back(6);
        sourceOf[1].push_back(6);
        sourceOf[1].push_back(8);
        sourceOf[2].push_back(7);
        sourceOf[2].push_back(9);
        sourceOf[3].push_back(4);
        sourceOf[3].push_back(8);
        sourceOf[4].push_back(0);
        sourceOf[4].push_back(3);
        sourceOf[4].push_back(9);
        sourceOf[6].push_back(0);
        sourceOf[6].push_back(1);
        sourceOf[6].push_back(7);
        sourceOf[7].push_back(6);
        sourceOf[7].push_back(2);
        sourceOf[8].push_back(1);
        sourceOf[8].push_back(3);
        sourceOf[9].push_back(2);
        sourceOf[9].push_back(4);
        
        vector<long long> past(10, 1);
        vector<long long> present(10, 1);
        
        for (int step = 2; step <= n; ++step) {
            std::fill(present.begin(), present.end(), 0);
            
            for (int key = 0; key <= 9; ++key) {
                if (!sourceOf[key].empty()) {
                    for (const auto& source: sourceOf[key]) {
                        present[key] += past[source];
                        present[key] %= MOD;
                    }
                }
            }
            past = present;
        }
        
        long long ans = 0;
        
        for (int i = 0; i < 10; ++i) {
            ans += (present[i] % MOD);
            ans %= MOD;
        }
        
        return ans;
    }
};