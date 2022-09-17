class Solution {
public:
  bool validDist(vector<int>& position, int possibleAns, int balls) {
    int prev = position[0], count = 1; // took the first one in hand and find the suitable next one
    for (int i = 1; i < position.size(); i++) {
      if (position[i] - prev >= possibleAns) {
        prev = position[i]; // update the prev and find the suitable next one
        count++;
      }
    }
    return count >= balls;
  }
    
  int binarySearch(vector<int>& position, int balls) {
    // search space is between 1 to max distance
    int b = 1, e = *(position.end() - 1) - position[0], mid, ans = -1;
    while (b <= e) {
      mid = (b + e) / 2;
      if (validDist(position, mid, balls)) {
        ans = mid; // possible ans
        b = mid + 1; // search for greater ans
      } else {
        e = mid - 1; // discard right part ans search for smaller ans
      }
    }
    return ans;
  }
  
  int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());
    return binarySearch(position, m);
  }
};