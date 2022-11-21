class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        stack<int> st;
        vector<int> ans(n);
        st.push(-1);

        for (int i = n - 1; i >= 0; i--) {
          int cur = arr[i];

          if (st.top() < cur) {
            ans[i] = st.top();
          } else {
            while (st.top() >= cur) {
              st.pop();
            }
            ans[i] = st.top();
          }
          st.push(cur);
        }

        return ans;
    } 
};
