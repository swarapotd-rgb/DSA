class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        pair<int, int> source = {0,0};
        pair<int, int> dest = {n-1, n-1};
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(n,1e9));
        dist[source.first][source.second] = 1;
        q.push({1, {source.first, source.second}});
        int delrow[] = {-1, -1 , -1, 0,0,1,1,1};
        int delcol[] = {-1 ,0, 1, -1, 1, -1, 0, 1};
        if(grid[0][0] ==1 || grid[n-1][n-1 ]== 1)
            return -1;
        if(n == 1)
            return 1;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            for(int i = 0; i<8; i++)
            {
                int nr = r + delrow[i];
                int nc = c + delcol[i];
                if(nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0 && dis + 1 < dist[nr][nc])
                {
                    dist[nr][nc] = dis +1;
                    if(nr == dest.first && nc == dest.second)
                        return dis + 1;
                    q.push({dis+1, {nr, nc}});
                }
                

            }

        }
        return -1;
        
    }
};