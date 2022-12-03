class Solution {
public:
  bool isPossible(vector<int>& weights, int days, int possibleAns) {
    int sum = 0, n = weights.size(), dayCount = 1;
    
    for (int i = 0; i < n; i++) {
      if (weights[i] > possibleAns) { // assumed ans is smaller than single element 
        return false; // impossible to considered as ans
      }
      if (sum + weights[i] <= possibleAns) { // increase sum if possible
        sum += weights[i];
      } else { 
        dayCount++; // get a new day
        if (dayCount > days) { // if days overflow 
          return false; // impossible to considered as ans
        }
        sum = weights[i]; // new day, new weights
      }
    }
    return true;
  }
  
  int shipWithinDays(vector<int>& weights, int days) {
    int b = 1, sum = 0, n = weights.size(), m, ans = -1;
    for (int i = 0; i < n; i++) {
      sum += weights[i];
    }
    int e = sum;
    // search space is 1 to the sum of elements
    while (b <= e) {
      m = b + (e - b) / 2;
      if (isPossible(weights, days, m)) { // possible ans
        ans = m;
        e = m - 1; // discard right part to search more minimum ans
      } else {
        b = m + 1; // discard left part because we need greater mid values
      }
    }
    
    return ans;
  }
};

