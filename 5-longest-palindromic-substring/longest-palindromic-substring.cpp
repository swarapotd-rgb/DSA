class Solution {
public:
    string longestPalindrome(string s) {
        int maxlen = 1, start = 0;
        for(int i = 0; i<s.size(); i++)
        {
            int left = i, right = i;
            while(left>=0 && right<s.size() && s[left] == s[right])
            {
                if(right-left+1 > maxlen)
                {
                    maxlen =right-left+1;
                    start = left;
                }
                left--;
                right++;
            }
            left = i, right = i+1;
            while(left>=0 && right<s.size() && s[left] == s[right])
            {
                if(right-left+1 > maxlen)
                {
                    maxlen =right-left+1;
                    start = left;
                }
                left--;
                right++;
            }     

        }
        return s.substr(start, maxlen);
        
    }
};