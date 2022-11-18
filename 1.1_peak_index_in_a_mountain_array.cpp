class Solution {
public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int b = 0, e = arr.size() - 1, m, n = arr.size();
    
    while (b <= e) {
      m = b + (e - b) / 2;
      
      if (m == 0 || arr[m] < arr[m + 1]) { 
        // mid is the first index
        // or mid is smaller than the right one
        // go right
        b = m + 1;
      } else if (m == n - 1 || arr[m] < arr[m - 1]) { 
        // mid is the last index
        // or mid is smaller than the left one
        // go left
        e = m - 1;
      } else {
        // mid is in between the range
        // and mid is the peak
        break;
      }
    }
    
    return m;
  }
}; 