class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r=0, hash[256], n = s.size(), maxlen = 0;
        for(int i = 0; i<n; i++)
        {
            hash[s[i]] = -1;
        }

        while(r<n)
        {
            if(hash[s[r]] != -1)
            {
                l = max(hash[s[r]] + 1, l);
            }
            int len = r - l +1;
            maxlen = max(maxlen, len);
            hash[s[r]] = r;
            r++;

        }
        return maxlen;
    }
};