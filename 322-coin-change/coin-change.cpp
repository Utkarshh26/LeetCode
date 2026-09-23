class Solution {
    int helper(int idx, int tar, vector<vector<int>>&dp,vector<int>&coins){
        if(idx ==0){
            if(tar%coins[0] ==0){
                return tar/coins[0];
            }
            return 1e9;
        }
        if(dp[idx][tar] !=-1){
            return dp[idx][tar];
        }
        int notpick =helper(idx-1,tar,dp,coins);
        int pick = 1e9;
        if(coins[idx] <=tar){
            pick =1 +helper(idx,tar-coins[idx],dp,coins);
        }
        return dp[idx][tar] =min(notpick,pick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int ans = helper(n-1,amount,dp,coins);
        return ans >= 1e9 ?-1 :ans;
    }
};