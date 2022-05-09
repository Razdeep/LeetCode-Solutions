// https://leetcode.com/problems/minimum-number-of-buckets-required-to-collect-rainwater-from-houses/
class Solution {
public:
    int minimumBuckets(string street) {
        int n = int(street.size());
        if (n == 1) {
            if (street[0] == 'H') {
                return -1;
            } else {
                return 0;
            }
        } 

        bool ok = true;
        int cnt = 0;
        
        if (street[0] == 'H' and street[1] == 'H') {
            ok = false;
        }
        
        if (street[n - 1] == 'H' and street[n - 2] == 'H') {
            ok = false;
        }
        
        for (int i = 0; i < n; ++i) {
            if (street[i] == '.') {
                if (i - 1 >= 0 and street[i - 1] == 'H') {
                    if (i - 2 >= 0) {
                        if (street[i - 2] != 'B') {
                            street[i] = 'B';
                            cnt++;
                            continue;
                        }
                    } else {
                        street[i] = 'B';
                        cnt++;
                        continue;
                    }
                }
                if (street[i + 1] == 'H') {
                    if (i + 2 < n) {
                        if (street[i + 2] == '.') {
                            street[i + 2] = 'B';
                            cnt++;
                            continue;
                        } else {
                            street[i] = 'B';
                            cnt++;
                            continue;
                        }
                    } else {
                        street[i] = 'B';
                        cnt++;
                        continue;
                    }
                }
                
            }
            
            if (i + 2 < n and street[i] == street[i + 1] and street[i + 1] == street[i + 2] and street[i + 2] == 'H') {
                ok = false;
            }
        }
        
        return ok ? cnt : -1;
    }
};