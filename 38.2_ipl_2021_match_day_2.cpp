class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        deque<int> dq;
        vector<int> ans;

        // we are maintaining a q which is decreasing from the front
        for (int i = 0; i < n; i++) {
            // first, remove out of boundary indices from the dq
            while (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }

            // second, remove the element which is smaller than current element from the back
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }

            dq.push_back(i);
            if (i >= k - 1) {
                ans.push_back(arr[dq.front()]);
            }
        }

        return ans;
    }
};
