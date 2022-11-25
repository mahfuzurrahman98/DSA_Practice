class MinStack {
public:
    stack<long long> st;
    long long mn;
    
    MinStack() {
        
    }
    
    void push(int val) {
      if(st.empty()) {
          st.push(val);
          mn = val;
      } else if (val >= mn) {
        st.push(val);
      } else {
        long long z = 2 * (long long)val - mn;
        st.push(z);
        mn = val;
      } 
    }
    
    void pop() {
      if (st.top() >= mn) {
        st.pop();
      } else {
        long long z = 2 * mn - st.top();
        st.pop();
        mn = z;
      }
    }
    
    int top() {
        if (st.top() >= mn) {
          return st.top();
        } else {
          return mn;
        }
    }
    
    int getMin() {
        return mn;
    }
};
