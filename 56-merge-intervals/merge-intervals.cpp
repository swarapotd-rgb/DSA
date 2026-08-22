class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i = 0; i<intervals.size(); i++)
        {
            int currstart = intervals[i][0];
            int currend = intervals[i][1];
            if(currstart <= end)
            {
                end = max(end, currend);
            }
            else
            {
                ans.push_back({start, end});
                start = currstart;
                end = currend;
            }
        }
        ans.push_back({start, end});
        return ans;
        
    }
};