class MinStack {
public:
  stack<int> st;
  int mn = INT_MAX;
    
  void push(int val) {
    if (val <= mn) {
      // we'll push previous min value into the stack before pushing new min val,
      // coz when we'll pop eg. min element then we need to update mn with prev min value 
      st.push(mn); //we'll use it to update mn when popping min element
      mn = val; //update mn with min val
    }
    st.push(val);
  }
    
  void pop() {
    if (st.top() == mn) {
      // this means mn got updated here, 
      // and we know that we have stored previous min value in stack before pushing new min
      st.pop(); // popping curr min value 
      mn = st.top(); // this is our previous min value, we'll update mn, and now we'll pop it as well!
    }
    st.pop();
  }
    
  int top() {
    return st.top();
  }
  
  int getMin() {
      return mn;
  }
};
