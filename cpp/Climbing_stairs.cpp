// Category: Dynamic Programming
// https://leetcode.com/problems/climbing-stairs/description/
#include<bits/stdc++.h>
using namespace std;
// Explanation: If we analyze the problem properly,
//              we can find that this is nothing but fibonacci series

// Working area starts here
class Solution {
public:
    int climbStairs(int n) {
        if(n==0)
        return 0;
        else if(n==1)
        return 1;
        else
        {
            int a=0,b=1,c;
            for(int i=0;i<n;i++)
            {
                c=a+b;
                a=b;
                b=c;
            }
            return c;
        }
    }
};
// Working area ends here
int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stringToInteger(line);
        
        int ret = Solution().climbStairs(n);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}