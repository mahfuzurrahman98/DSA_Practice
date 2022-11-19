class Solution
{
    private:
    void rec(stack<int>&s, int i, int m) {
        if (i == m) {
            s.pop();
            return;
        }
        
        int top = s.top();
        s.pop();
        
        rec(s, i + 1, m);
        s.push(top);
    }
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        int m = sizeOfStack / 2;
        rec(s, 0, m);
    }
};
