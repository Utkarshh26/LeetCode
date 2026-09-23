class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        for(int i = 0; i <= amount; i++) {
            if(i % coins[0] == 0){
                 dp[0][i] = i/coins[0];
            }else{
                dp[0][i] = 1e9;
            }        
        }

        for(int idx = 1; idx < n; idx++) {
            for(int tar = 0; tar <= amount; tar++) {
                int notpick = dp[idx - 1][tar];
                int pick = 1e9;

                if(coins[idx] <= tar) {
                    pick = 1 + dp[idx][tar - coins[idx]];
                }
                dp[idx][tar] = min(pick, notpick);
            }
        }
        int ans = dp[n - 1][amount];
        return ans >= 1e9 ? -1 : ans;
    }
};