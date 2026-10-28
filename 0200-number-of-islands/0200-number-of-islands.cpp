class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& visited,
             vector<vector<char>>& grid, int n, int m) {

        visited[row][col] = 1;

        // Fix 1: size 4, hamesha
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol  = {0, 1, 0, -1};

        // Fix 2: sirf 4 directions, ek loop
        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];   // Fix 3: int declare karo
            int ncol  = col + delcol[i];   // Fix 3: same i

            if(nrow >= 0 && nrow < n &&    // Fix 4: < not <=
               ncol >= 0 && ncol < m &&
               !visited[nrow][ncol] &&
               grid[nrow][ncol] == '1') {  // Fix 5: '1' char hai
                dfs(nrow, ncol, visited, grid, n, m);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Fix 6: lowercase 'visited'
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int island = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    dfs(i, j, visited, grid, n, m);  // Fix 6: no delrow/delcol
                    island++;
                }
            }
        }
        return island;
    }
};