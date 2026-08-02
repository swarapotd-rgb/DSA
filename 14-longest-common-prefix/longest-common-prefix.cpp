class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string cp = strs[0];
        for(int i = 0; i< strs.size(); i++)
        {
            int j = 0;
            while(j<cp.size() && j<strs[i].size())
            {
                if(cp[j] == strs[i][j])
                {
                    j++;
                }
                else
                {
                    break;
                }
            }
            cp = cp.substr(0,j);
        }
    return cp;
    }   
};