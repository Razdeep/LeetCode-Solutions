// Category: Dynamic Programming
// https://leetcode.com/problems/min-cost-climbing-stairs/description/
#include<bits/stdc++.h>
using namespace std;

// Working area starts here
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> minCost(cost.size()+2,0);
        for(int i=cost.size()-1;i>=0;--i)
        {
            minCost[i]=cost[i]+min(minCost[i+1],minCost[i+2]);
        }
        return min(minCost[0],minCost[1]);
    }
};
// Working area ends here

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> cost = stringToIntegerVector(line);
        
        int ret = Solution().minCostClimbingStairs(cost);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}