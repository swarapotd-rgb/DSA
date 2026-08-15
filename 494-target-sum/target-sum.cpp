class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(int x : nums)
        {
            total += x;
        }
        if(target > total || target < -total)
        {
            return 0;
        }
        vector<vector<int>> dp(n+1, vector<int>(2*total +1, 0));
        dp[0][total] = 1;
        for(int i = 0; i<n; i++)
        {
            for(int sum = -total; sum <= total; sum++)
            {
                int index = sum + total;
                if(dp[i][index] == 0)
                    continue;
                int newsum = sum + nums[i];
                dp[i+1][newsum + total] += dp[i][index];
                newsum = sum - nums[i];
                dp[i+1][newsum + total] += dp[i][index];
                
                
            }
        }
        return dp[n][target+total];
    }
};