class Solution {
public:
    int change(int amount, vector<int>& coins) {
        const long long LIMIT = INT_MAX;
        vector<long long> dp(amount+1,0);
        dp[0] = 1;
        for(int coin : coins)
        {
            for(int a = coin; a <= amount; a++)
            {
                if(dp[a - coin] > LIMIT - dp[a])
                {
                    dp[a] = LIMIT;
                }
                else
                {
                    dp[a] += dp[a - coin];
                }
            }
        }
        return (int)dp[amount];
    }
};