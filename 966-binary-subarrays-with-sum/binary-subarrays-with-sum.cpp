class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int, int> freq;
        int sum =0, count = 0;
        freq[0] = 1;
        for(int x  : nums)
        {
            sum += x;
            int needed = sum - goal;
            if(freq.find(needed) != freq.end())
            {
                count += freq[needed];
            }
            freq[sum]++;
        }
        return count;
    }
};