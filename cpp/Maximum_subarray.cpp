// Category: Dynamic Programming
// https://leetcode.com/problems/maximum-subarray/description/

// Explanation: This is actually the implementation of KADANE's Algorithm

#include<bits/stdc++.h>
using namespace std;
// Working area starts here
class Solution{
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0)
        return 0;
        else
        {
            int maxGlobal=nums[0];
            vector<int> maxLocal(nums.size(),INT_MIN);
            maxLocal[0]=nums[0];
            for(int i=1;i<nums.size();i++)
            {
                maxLocal[i]=max(nums[i],maxLocal[i-1]+nums[i]);
                if(maxLocal[i]>maxGlobal)
                maxGlobal=maxLocal[i];
            }
            return maxGlobal;
        }
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
        
        int ret = Solution().maxSubArray(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}