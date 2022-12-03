#include <bits/stdc++.h> 
long long sumOfMaxAndMin(vector<int> &nums, int n, int k) {
	deque<int> dq1, dq2;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        // first find the minimum
        // we are maintaining a q which is decreasing from the front
        // first, remove out of boundary indices from the dq
        while (!dq1.empty() && dq1.front() < i - k + 1) {
            dq1.pop_front();
        }
        // second, remove the element which is smaller than current element from the back
        while (!dq1.empty() && nums[dq1.back()] >= nums[i]) {
            dq1.pop_back();
        }
        dq1.push_back(i);
        
        //--------------------------------------------------------------------------------------
        
        
        // now find the maximum
        // we are maintaining a q which is increasing from the front
        // first, remove out of boundary indices from the dq
        while (!dq2.empty() && dq2.front() < i - k + 1) {
            dq2.pop_front();
        }
        // second, remove the element which is smaller than current element from the back
        while (!dq2.empty() && nums[dq2.back()] <= nums[i]) {
            dq2.pop_back();
        }
        dq2.push_back(i);
        
        
        if (i >= k - 1) { // valid window size
            ans += nums[dq1.front()];
            ans += nums[dq2.front()];
        }
    }

    return ans;
}
