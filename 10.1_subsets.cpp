class Solution {
public:
  void dfs(vector<int> nums, vector<int> cur, int i, vector<vector<int>>& ans) {
    if (i == nums.size()) { // reached the leaf nodes
      ans.push_back(cur); // push it to the answer
      return;
    }
    
    dfs(nums, cur, i + 1, ans); // call the next step as it is, not including the ith element
    
    cur.push_back(nums[i]); // include the ith element
    dfs(nums, cur, i + 1, ans); // call next step with new element added
  }
  
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    dfs(nums, {}, 0, ans);
    return ans;
  }
};
