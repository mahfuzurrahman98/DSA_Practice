class Solution{

private:
public:
    void pushAtBottom(stack<int>& st, int x) {
        if (st.empty()) {
            st.push(x);
            return;
        }
        int top = st.top();
        st.pop();
        pushAtBottom(st, x);
        st.push(top);
    }

    void Reverse(stack<int> &st) {
        if (st.empty()) {
            return;
        }
        
        int top = st.top();
        st.pop();
        
        Reverse(st);
        pushAtBottom(st, top);
    }
};
