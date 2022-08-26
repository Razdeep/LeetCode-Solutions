// https://leetcode.com/problems/peak-index-in-a-mountain-array/
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = int(arr.size());
        int low = 0, high = n;
        int ans = -1;
        
        while (high - low > 0) {
            int mid = (high + low) / 2;
            if (arr[mid - 1] < arr[mid] and arr[mid] > arr[mid + 1]) {
                ans = mid;
                break;
            } else if (arr[mid - 1] < arr[mid] and arr[mid] < arr[mid + 1]) {
                low = mid;
            } else {
                high = mid;
            }
        }
        
        return ans;
    }
};