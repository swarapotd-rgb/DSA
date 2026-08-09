class Solution {
private:
    void dfs(int row, int col, int baseRow, int baseCol, vector<vector<int>> &vis, vector<vector<char>> &grid, vector<pair<int, int>> &shape)
    {
        vis[row][col] = 1;
        shape.push_back({row - baseRow, col - baseCol});
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0; i<4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == '1')
            {
                dfs(nrow, ncol, baseRow, baseCol, vis, grid, shape);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        int count = 0;
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(grid[i][j] == '1' && !vis[i][j])
                {
                    vector<pair<int, int>> shape;
                    dfs(i, j, i, j, vis, grid, shape);
                    count++;
                }
            }
        }
        return count;

        
    }
};