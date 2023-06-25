// bridges in a graph using tarjan's algorithm

class Solution {
    int time = 1;
public:
    void dfs(int current, int parent, const vector<vector<int> >& graph,
            vector<bool>& visited, vector<int>& time_of_insertion,
            vector<int>& lowest_time, vector<vector<int> >& critical_connections) {

        visited[current] = true;
        lowest_time[current] = time_of_insertion[current] = time++;
        
        for (int neighbour: graph[current]) {
            if (neighbour == parent) continue;
            if (!visited[neighbour]) {
                dfs(neighbour, current, graph, visited, time_of_insertion, lowest_time, critical_connections);
                lowest_time[current] = min(lowest_time[current], 
                                            lowest_time[neighbour]);
                if (time_of_insertion[current] < lowest_time[neighbour]) {
                    critical_connections.push_back({current, neighbour});
                }
            } else {
                lowest_time[current] = min(lowest_time[current], 
                                            lowest_time[neighbour]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int> > graph(n, vector<int>());
        
        for (const vector<int>& connection: connections) {
            int x = connection[0];
            int y = connection[1];
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        vector<bool> visited(n, false);
        vector<int> time_of_insertion(n, 0);
        vector<int> lowest_time(n, 0);
        vector<vector<int> > critical_connections;

        dfs(0, -1, graph, visited, time_of_insertion, lowest_time, critical_connections);

        return critical_connections;
    }
};