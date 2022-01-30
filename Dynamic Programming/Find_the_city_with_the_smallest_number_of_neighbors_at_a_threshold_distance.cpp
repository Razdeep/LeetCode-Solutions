// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/submissions/
class Solution {
    constexpr static int oo = int(1e9);
    
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int> > distance(n, vector<int>(n, oo));
        
        enum EdgeField { FROM, TO, WEIGHT };
        
        for (const auto& edge: edges) {
            distance[edge[FROM]][edge[TO]] = edge[WEIGHT];
            distance[edge[TO]][edge[FROM]] = edge[WEIGHT];
        }
        
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (i != j) {
                        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                    }
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            distance[i][i] = 0;
        }
        
        vector<int> threshold_connections(n, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                threshold_connections[i] += (distance[i][j] <= distanceThreshold);
            }
        }
        
        int ans_connected = oo;
        int ans_index = -1;
        
        for (int i = 0; i < n; ++i) {
            if (threshold_connections[i] <= ans_connected) {
                ans_connected = threshold_connections[i];
                ans_index = i;
            }
        }
        
        return ans_index;
    }
};