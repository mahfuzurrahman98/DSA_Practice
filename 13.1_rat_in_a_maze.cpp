class Solution{https://practice.geeksforgeeks.org/explore
    public:
    bool isValid(vector<vector<int>> &m, int n, vector<vector<int>> vis, int x, int y) {
        return ((x >= 0 && x < n) && (y >= 0 && y < n)) && m[x][y] == 1 && vis[x][y] == 0;
    }
    void dfs(vector<vector<int>> &m, int n, vector<vector<int>>& vis, int x, int y, string path, vector<string>& ans) {
        if (x == n - 1 && y == n - 1) { // reached the destination
            ans.push_back(path); // push path to the answer
            return;
        }
        
        vis[x][y] = 1; // mark the current cell visited
        int dx, dy;
        
        // go left
        if (isValid(m, n, vis, x, y - 1)) { // check the next move is valid or not
            dfs(m, n, vis, x, y - 1, path + 'L', ans); // call the next move with updated path
        }
        
        // go up
        if (isValid(m, n, vis, x - 1, y)) { // check the next move is valid or not
            dfs(m, n, vis, x - 1, y, path + 'U', ans); // call the next move with updated path
        }
        
        // go right
        if (isValid(m, n, vis, x, y + 1)) { // check the next move is valid or not
            dfs(m, n, vis, x, y + 1, path + 'R', ans); // call the next move with updated path
        }
        
        // go down
        if (isValid(m, n, vis, x + 1, y)) { // check the next move is valid or not
            dfs(m, n, vis, x + 1, y, path + 'D', ans); // call the next move with updated path
        }
        
        vis[x][y] = 0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>> vis = m;
        vector<string> ans;
        
        if (m[0][0] == 0) {
            return ans;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                vis[i][j] = 0;
            }
        }
        dfs(m, n, vis, 0, 0, "", ans);
       
        return ans;
    }
};

