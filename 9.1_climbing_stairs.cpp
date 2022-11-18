class Solution {
public:
  int fib(int n, int* dp) {
    if (n == -1) {
      return 0;
    }
    if (n == 0) {
      return 1;
    }
    if (dp[n] > 0) {
      return dp[n];
    }
    dp[n] = fib(n - 1, dp) + fib(n - 2, dp);
    return dp[n];
  }
  
  int climbStairs(int n) {
    int* dp = new int[50];
    return fib(n, dp);
  }
};
