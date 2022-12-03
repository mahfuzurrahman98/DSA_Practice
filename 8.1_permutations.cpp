class Solution {
public:
  void dfs(vector<int> nums, vector<vector<int>>& ans, int index) {
    if (index == nums.size() - 1) { // reached the leaf nodes
      ans.push_back(nums); // push it to the ans
      return; // return back
    }
    
    for (int i = index; i < nums.size(); i++) { // loop through the indexes
      swap(nums[i], nums[index]); // swap the place of ith index with original index to get a new permutation
      dfs(nums, ans, index + 1); // call the next step with (swaped placed nums and next index)
      swap(nums[i], nums[index]); // get back the previous nums 
    }
  }
  
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> ans;
    dfs(nums, ans, 0);
    return ans;
  }
};

