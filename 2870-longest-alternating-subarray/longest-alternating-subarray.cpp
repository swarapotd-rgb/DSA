class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        int ans = -1;
        while(i < n-1)
        {
            if((nums[i+1] - nums[i]) != 1)
            {
                i++;
                continue;
            }
            int j = i+1;
            while(j+1<n && nums[j+1] == nums[j-1])
            {
                j++;
            }
            ans = max(ans, j-i+1);
            i=j;
        }
    return ans;
    }
};