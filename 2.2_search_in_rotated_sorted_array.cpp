class Solution {
public:
  int peakIndex(vector<int>& arr, int target) {
    int b = 0, e = arr.size() - 1, m, n = arr.size(), ans;

    ans = 0;
    while (b <= e) {
      m = b + (e - b) / 2;
      if (arr[m] == target) {
        return m;
      }
      if (arr[m] >= arr[b]) { // check if it is increasing from star to mid
        if (target >= arr[b] && target < arr[m]) { // ans lies in the left part
          e = m - 1; // discard the right part
        } else {
          b = m + 1; // discard the left
        }
      } else if (arr[e] >= arr[m]) { // check if it is increasing from mid to end
        if (target > arr[m] && target <= arr[e]) { // ans lies in the right part
          b = m + 1; // discard the left
        } else {
          e = m - 1; // discard the right part
        }
      }
    }
    return -1;
  }


  int search(vector<int>& nums, int target) {
    int n = nums.size();
    int peak = peakIndex(nums, target);

    return peak;
  }
};