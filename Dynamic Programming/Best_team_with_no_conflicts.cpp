// https://leetcode.com/problems/best-team-with-no-conflicts/
class Solution {
public:
    struct Player {
        int score, age;
        Player(int score, int age): score(score), age(age) {}
    };
    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = int(scores.size());
        vector<Player> players;
        
        for (int i = 0; i < n; ++i) {
            players.emplace_back(scores[i], ages[i]);
        }
        
        sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
            if (a.age == b.age) return a.score < b.score;
            return a.age < b.age;
        });
        
        vector<int> dp(n, 0);
        
        dp[0] = players[0].score;
        
        for (int i = 1; i < n; ++i) {
            dp[i] = players[i].score;
            for (int j = 0; j < i; ++j) {
                
                if (players[i].score >= players[j].score) {
                    dp[i] = max(dp[i], dp[j] + players[i].score);
                }
            }
        }
        
        return *max_element(dp.begin(), dp.end());
    }
};