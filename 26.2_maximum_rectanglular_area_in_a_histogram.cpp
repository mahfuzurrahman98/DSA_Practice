class Solution
{
    private:
    void prevSmallest(long long heights[], vector<int>& prev, int n) {
    stack<int> st;
    st.push(-1);

    for (int i = 0; i < n; i++) {
      // we need element which is smaller than
      // or equal to the current element
      while (st.top() != -1 && heights[st.top()] >= heights[i]) {
        // found greater or equal element, so go deep
        // in case -1 found loop will break
        // and -1 will be considered as top
        st.pop();
      }
      int top = st.top();
      prev[i] = top;

      st.push(i);
    }
  }

  void nextSmallest(long long heights[], vector<int>& next, int n) {
    stack<int> st;
    st.push(n);

    for (int i = n - 1; i >= 0; i--) {
      // we need element which is smaller than
      // or equal to the current element
      while (st.top() != n && heights[st.top()] >= heights[i]) {
        // found greater or equal element, so go deep
        // in case -1 found loop will break
        // and -1 will be considered as top
        st.pop();
      }
      int top = st.top();
      next[i] = top;

      st.push(i);
    }
  }
  
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long heights[], int n)
    {
        long long ans = -1;
        vector<int> prev(n), next(n);
    
        prevSmallest(heights, prev, n);
        nextSmallest(heights, next, n);
    
        for (int i = 0; i < n; i++) {
          long long w = next[i] - prev[i] - 1;
          long long h = heights[i];
    
          long long area = w * h;
          ans = max(ans, area);
        }
        return ans;
    }
};

