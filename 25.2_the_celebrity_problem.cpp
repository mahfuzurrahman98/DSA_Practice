class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            st.push(i);
        }
        
        while (st.size() > 1) {
            // as we have to pick two elements each time
            int x = st.top(); st.pop();
            int y = st.top(); st.pop();
            
            if (M[x][y] == 1) {
                // x knows y, x isn't a celebrity
                // y is known by x, y could be a celebrity
                st.push(y);
            } else {
                // x doesn't know y, x could be a celebrity
                // y isn't known by x, y isn't a celebrity
                st.push(x);
            }
        }
        
        int x = st.top();
        // x could be a celebrity
        
        for (int i = 0; i < n; i ++) {
            if (i != x && M[x][i] == 1) { 
                // x knows i, x isn't a celebrity
                return -1;
            }
        }
        
        for (int i = 0; i < n; i ++) {
            if (i != x && M[i][x] == 0) { 
                // i doesn't know x, x isn't a celebrity
                return -1;
            }
        }
        
        return x;
    }
};
