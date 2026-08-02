class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size()-1;
    int ans = nums.size();
    int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    while(low<=high)
    {
        int mid = low + (high - low)/2;
        if(nums[mid] > target)
        {
            ans = mid;
            high = mid -1;
        }
        else
        {
            low = mid+1;
        }
    }
    if(lb == nums.size() || nums[lb] != target) return {-1, -1};
    else return {lb, ans-1};   
    }
};