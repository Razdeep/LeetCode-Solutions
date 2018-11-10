// Category: Dynamic Programming
// https://leetcode.com/problems/house-robber/description/

#include<bits/stdc++.h>
using namespace std;

// Working area starts here
class Solution {
public:
    int rob(vector<int>& nums) {
        if(!nums.size())
        return 0;
        if(nums.size()==1)
        return nums[0];
        if(nums.size()==2)
        return max(nums[0],nums[1]);
        vector<int> loot(nums.size(),0);
        loot[0]=nums[0];
        loot[1]=nums[1];
        loot[2]=nums[2]+nums[0];
        int maxLoot=max(loot[0],max(loot[1],loot[2]));
        for(int i=3;i<nums.size();i++)
        {
            loot[i]=nums[i]+max(loot[i-2],loot[i-3]);
            if(loot[i]>maxLoot)
            maxLoot=loot[i];
        }
        return maxLoot;
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
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().rob(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}