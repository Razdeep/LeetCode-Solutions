// Category: Dynamic Programming
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include<bits/stdc++.h>
using namespace std;

// Working area starts
class Solution {
public:
    int minimum(int a,int b){ return a<b?a:b; }
    int maxProfit(vector<int>& prices) {
        // This solution was not giving correct output for all the cases
        // if(prices.size()==0)
        // return 0;
        // vector<int>::iterator minItr=min_element(prices.begin(),prices.end());
        // int minElement=*minItr;
        // int maxElement=(*max_element(minItr,prices.end()));
        // int ans=(maxElement-minElement)>0?(maxElement-minElement):0;
        // This solution ends here

        // New solution
        if(!prices.size())
        return 0;
        // precomputing the values of the minimum_till_date stock prices
        vector<int> minimum_till_date(prices.size(),0);
        int currentMinimum=INT_MAX;
        minimum_till_date[0]=prices[0]; // Minimum stock price of first day is itself
        for(int i=1;i<prices.size();i++)
        {
            minimum_till_date[i]=minimum(prices[i],minimum_till_date[i-1]);
        }
        int ans=INT_MIN;
        for(int i=0;i<minimum_till_date.size();i++)
        {
            int currentProfit=prices[i]-minimum_till_date[i];
            if(currentProfit>ans)
            ans=currentProfit;
        }
        return ans;
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
        vector<int> prices = stringToIntegerVector(line);
        
        int ret = Solution().maxProfit(prices);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}