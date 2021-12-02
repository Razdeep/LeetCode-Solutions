// https://leetcode.com/problems/rotated-digits/
class Solution {
public:
    set<int> allowed_digits;
    set<int> required_digits;

    bool isGood(int n) {
        bool atleast_having_required_digit = false;
        while (n > 0) {
            int digit = n % 10;
            if (required_digits.find(digit) != required_digits.end()) {
                atleast_having_required_digit = true;
            } else if (allowed_digits.find(digit) != allowed_digits.end()) {
                
            } else {
                return false;
            }
            n /= 10;
        }
        
        return atleast_having_required_digit;
    }
    
    int rotatedDigits(int n) {
        int ans = 0;
        allowed_digits.insert(0);
        allowed_digits.insert(1);
        allowed_digits.insert(8);
        required_digits.insert(2);
        required_digits.insert(5);
        required_digits.insert(6);
        required_digits.insert(9);
        
        for (int i = 1; i <= n; ++i) {
            ans += isGood(i);
        }
        return ans;
    }
};