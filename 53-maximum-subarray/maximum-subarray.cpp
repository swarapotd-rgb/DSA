class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int start, ansstart = -1, ansend = -1, sum = 0, maxi = INT_MIN;
        for(int i = 0; i<nums.size(); i++)
        {
            if(sum == 0) start = i;
            sum += nums[i];
            if (sum > maxi)
            {
                maxi = sum;
                ansstart = start;
                ansend = i;
            }
            if(sum < 0)
                sum = 0;
        }
        return maxi;
    }
};