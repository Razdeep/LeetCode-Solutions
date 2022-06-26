// https://leetcode.com/problems/count-subtrees-with-max-distance-between-cities/
class Solution {
    static constexpr int oo = int(1e9);
public:
    int calculateLongestDistance(const vector<vector<int> >& distance, int state) {
        int n = int(distance.size());
        int max_distance = 0;
        int vertices_count = 0;
        int edges_count = 0;
        
        for (int i = 0; i < n; ++i) {
            if ((state & (1 << i)) == 0) {
                continue;
            }
            vertices_count++;
            for (int j = i + 1; j < n; ++j) {
                if ((state & (1 << j)) == 0) {
                    continue;
                }
                edges_count += (distance[i][j] == 1);
                max_distance = max(max_distance, distance[i][j]);
            }
        }
        
        bool valid = (vertices_count == edges_count + 1);
        
        return valid ? max_distance : 0;
    }
    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        // Floyd warshall algorithm 
        vector<vector<int> > distance(n, vector<int>(n, oo));
        
        // Converting edges to distance vector
        for (int i = 0; i < int(edges.size()); ++i) {
            distance[edges[i][0] - 1][edges[i][1] - 1] = distance[edges[i][1] - 1][edges[i][0] - 1] = 1;
        }
        
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                }
            }
        }
        
        vector<int> ans(n - 1, 0);
        // Bitmasking
        for (int state = 0; state < (1 << n); ++state) {
            int longest_distance_for_current_state = calculateLongestDistance(distance, state);
            if (longest_distance_for_current_state == 0) {
                // Invalid configuration where the subset doesnt even for a proper tree
                continue;
            }
            ans[longest_distance_for_current_state - 1]++;
        }
        
        return ans;
    }
};