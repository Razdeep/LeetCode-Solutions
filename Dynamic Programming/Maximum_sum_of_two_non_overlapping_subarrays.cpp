class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& arr, int firstLen, int secondLen) {
        
        int n = int(arr.size());
        vector<int> prefix_sum(n, 0);
        
        prefix_sum[0] = arr[0];
        
        for (int i = 1; i < n; ++i) {
            prefix_sum[i] = prefix_sum[i - 1] + arr[i];
        }
        
        int ans = 0;
        
        for (int i = firstLen - 1; i < n; ++i) {
            int first_sum = prefix_sum[i] - (i - firstLen >= 0 ? prefix_sum[i - firstLen] : 0);
            int second_sum = 0;
            for (int j = secondLen - 1; (j < n) && (j < i - firstLen); ++j) {
                second_sum = max(second_sum, prefix_sum[j] - (j - secondLen >= 0 ? prefix_sum[j - secondLen] : 0));
            }
            for (int j = i; j + secondLen < n; ++j) {
                second_sum = max(second_sum, prefix_sum[j + secondLen] - prefix_sum[j]);
            }
            ans = max(ans, first_sum + second_sum);
        }
        
        
        return ans;
    }
};