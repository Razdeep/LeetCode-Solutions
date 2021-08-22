class Solution {
public:
    int calcPower(int x) {
        int res = 0;
        while (x > 1) {
            if (x & 1) {
                x = 3 * x + 1;
            } else {
                x /= 2;
            }
            res++;
        }
        return res;
    }
    
    static bool sortingMethod(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.second == b.second) {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
    
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int> > arr(hi - lo + 1);
        
        int cur = lo;
        
        for (int i = 0; i < hi - lo + 1; ++i) {
            arr[i].first = cur++;
            arr[i].second = calcPower(arr[i].first);
        }
        
        sort(arr.begin(), arr.end(), sortingMethod);
        
        return arr[k - 1].first;
    }
};