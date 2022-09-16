class Solution {
public:
  int binarySearch(int n) {
    int b = 1, e = min(INT_MAX, n), m, ans;
    
    while (b <= e) {
      m = b + (e - b) / 2;
      
      if (n / m == m) {
        return m;
      } else if (m < n / m) {
        ans = m; // possible ans
        b = m + 1; // search the right part as well
      } else {
        e = m - 1; // search the left part
      }
    }
    return ans;
  }
  
  int mySqrt(int x) {
    return binarySearch(x);
  }
};
