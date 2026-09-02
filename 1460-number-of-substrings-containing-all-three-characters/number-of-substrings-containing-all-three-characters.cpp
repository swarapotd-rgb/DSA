class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char, int> freq;
        int left = 0, ans = 0;
        for(int right = 0; right < s.size(); right++)
        {
            freq[s[right]]++;
            while(freq['a'] >=1 && freq['b'] >=1 && freq['c'] >=1 )
            {
                
                freq[s[left]]--;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};