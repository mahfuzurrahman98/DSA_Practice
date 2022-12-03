class Solution {
public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;
    int n = nums.size();

    // we are maintaining a q which is decreasing from the front
    for (int i = 0; i < n; i++) {
      // first, remove out of boundary indices from the dq
      while (!dq.empty() && dq.front() < i - k + 1) {
        dq.pop_front();
      }
      
      // second, remove the element which is smaller than current element from the back
      while (!dq.empty() && nums[dq.back()] <= nums[i]) {
        dq.pop_back();
      }

      dq.push_back(i);
      if (i >= k - 1) {
        ans.push_back(nums[dq.front()]);
      }
    }

    return ans;
  }
};
