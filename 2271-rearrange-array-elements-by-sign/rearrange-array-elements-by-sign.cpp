class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int posidx = 0, negidx = 1;
        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] < 0)
            {
                ans[negidx] = nums[i];
                negidx += 2;
            }
            else
            {
                ans[posidx] = nums[i];
                posidx += 2;
            }
        
        }
        return ans;
    }
};