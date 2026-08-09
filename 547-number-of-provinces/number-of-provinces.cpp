class Solution {
private:
    void dfs(int node, vector<int> adjl[], vector<int> &vis)
    {
        vis[node] = 1;
        for(auto neighbor : adjl[node])
        {
            if(!vis[neighbor])
            {
                dfs(neighbor, adjl, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adjl[V];
        for(int i = 0; i<V; i++)
        {
            for(int j = 0; j<V; j++)
            {
                if(isConnected[i][j] == 1 && i != j)
                {
                    adjl[i].push_back(j);
                    adjl[j].push_back(i);
                }
            }
        }
        vector<int> vis(V,0);
        int c = 0;
        for(int i = 0; i<V; i++)
        {
            if(!vis[i])
            {
                c++;
                dfs(i, adjl, vis);
            }
        }
        return c;

        
    }
};