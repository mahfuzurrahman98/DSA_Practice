class Solution {
public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int b = 0, e = arr.size() - 1, m, n = arr.size();
    
    while (b <= e) {
      m = b + (e - b) / 2;
      
      if (m == 0) { // mid is the first index, go right
        b = m + 1;
      } else if (m == n - 1) { // mid is the last index, go left
        e = m - 1;
      } else {
        if (arr[m] > arr[m - 1] && arr[m] > arr[m  + 1]) {
          return m;
        } else {
          if (arr[m] < arr[m - 1]) {
            e = m - 1;
          } else if (arr[m] < arr[m + 1]) {
            b = m + 1;
          }
        }
      }
    }
    return m;
  }
}; 
