class Solution {
private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int delrow[], int delcol[])
    {
        int n = mat.size();
        int m = mat[0].size();
        vis[row][col] = 1;
        for(int i =0; i<4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
            {
                dfs(nrow, ncol, vis, mat, delrow, delcol);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        if (n == 0 || m == 0 ) return;
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};
        vector<vector<int>> vis(n, vector<int>(m,0));
        for(int j = 0; j<m; j++)
        {
            if(board[0][j] == 'O' && !vis[0][j])
            {
                dfs(0, j, vis, board, delrow, delcol);
            }
            if(board[n-1][j] == 'O' && !vis[n-1][j])
            {
                dfs(n-1, j, vis, board, delrow, delcol);   
            }
        }
        for(int i = 0; i<n; i++)
        {
            if(board[i][0] == 'O' && !vis[i][0])
            {
                dfs(i, 0, vis, board, delrow, delcol);
            }
            if(board[i][m-1] == 'O' && !vis[i][m-1])
            {
                dfs(i, m-1, vis, board, delrow, delcol);   
            }
        }
        for(int i = 0; i<n; i++)
        {
            for(int j = 0; j<m; j++)
            {
                if(!vis[i][j] && board[i][j] == 'O')
                {
                    board[i][j] = 'X';
                }
            }
        }
        return;
    }
};