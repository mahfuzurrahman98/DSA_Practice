class Solution {
public:
  int peakIndex(vector<int>& arr) {
    int b = 0, e = arr.size() - 1, m, n = arr.size(), ans;
    
    ans = 0;
    while (b <= e) {
      m = b + (e - b) / 2;
      
      if (arr[m] >= arr[0]) { // check if it is increasing till mid
        ans = m; // mid is a poissible ans
        b = m + 1; // remove the left
      } else {
        e = m - 1; // remove the right
      }
    }
    
    return ans;
  }
  
  int binarySearch(vector<int>& nums, int beg, int end, int target) {
    int b = beg, e = end, m = -1;
    while (b <= e) {
      m = b + (e - b) / 2;
      if (nums[m] == target) {
        return m;
      } else if (nums[m] < target) {
        b = m + 1;
      } else {
        e = m - 1;
      }
    }
    return -1;
  }
  
  int search(vector<int>& nums, int target) {
    int n = nums.size();
    int peak = peakIndex(nums);

    if (nums[peak] == target) {
      return peak;
    } else if (target >= nums[0] && (peak > 0 && target <= nums[peak - 1])) { // search the left part
      return binarySearch(nums, 0, peak - 1, target);
    } else if ((peak < n - 1 && target >= nums[peak + 1]) && (target <= nums[n - 1])) { // search the right part
      return binarySearch(nums, peak + 1, n - 1, target);
    }
    return -1;
    
  }
};