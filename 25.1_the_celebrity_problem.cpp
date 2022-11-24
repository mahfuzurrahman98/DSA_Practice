class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int knows[n] = {0};
        int known[n] = {0};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (M[i][j] == 1) {
                    known[j]++;
                    knows[i]++;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (knows[i] == 0 && known[i] == n - 1) {
                return i;
            }
        }
        
        return -1;
    }
};
