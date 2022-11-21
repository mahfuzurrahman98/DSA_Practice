class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;
        int n = prices.size();
        vector<int> ans(n);
        st.push(0);

        for (int i = n - 1; i >= 0; i--) {
          int cur = prices[i];

          if (st.top() <= cur) {
            ans[i] = cur - st.top();
          } else {
            while (st.top() > cur) {
              st.pop();
            }
            ans[i] = cur - st.top();
          }
          st.push(cur);
        }

        return ans;
    }
};
