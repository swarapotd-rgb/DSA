class Solution {
private:
    bool dfs(int node, vector<vector<int>> &adjl, vector<int> &vis, vector<int> &pathvis)
    {
        vis[node] = 1;
        pathvis[node] = 1;
        for(auto it : adjl[node])
        {
            if(!vis[it])
            {
                if(dfs(it, adjl, vis, pathvis) == true)
                {
                    return true;
                }
            }
            else if(pathvis[it])
            {
                return true;
            }
            
        }
        pathvis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V = numCourses;
        vector<vector<int>> adjl(V);
        for( auto it : prerequisites)
        {
            int course = it[0];
            int pre = it[1];
            adjl[pre].push_back(course);

        }
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        for(int i = 0; i<V; i++)
        {
            if(!vis[i])
            {
                if(dfs(i, adjl, vis, pathvis) == true)
                    return false;
            }
        }
        return true;
    }
};