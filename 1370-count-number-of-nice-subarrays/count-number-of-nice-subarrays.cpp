class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int oddcount = 0, res = 0;
        freq[0] = 1;
        for(int x : nums)
        {
            if(x % 2 != 0)
            {
                oddcount++;
            }
            int needed = oddcount - k;
            if(freq.find(needed) != freq.end())
            {
                res += freq[needed];
            }
            freq[oddcount]++;
        }
        return res;
        
    }
};