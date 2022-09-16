class Solution {
public:
  int binarySearch(int n) {
    int b = 1, e = min(INT_MAX, n), ans;
    long long sq, m;
    
    while (b <= e) {
      m = b + (e - b) / 2;
      sq = m * m;
      if (sq == n) {
        return m;
      } else if (sq < n) {
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
