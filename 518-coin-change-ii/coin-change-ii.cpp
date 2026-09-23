class Solution {
    int helper(int idx, int tar, vector<vector<int>>&dp,vector<int>&coins){
        if(idx ==0){
            if(tar%coins[0] ==0){
                return 1;
            }
            return 0;
        }
        if(dp[idx][tar] !=-1){
            return dp[idx][tar];
        }
        int notpick =helper(idx-1,tar,dp,coins);
        int pick = 0;
        if(coins[idx] <=tar){
            pick = helper(idx,tar-coins[idx],dp,coins);
        }
        return dp[idx][tar] =pick+notpick;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1,-1));
        int ans = helper(n-1,amount,dp,coins);
        return ans ==0 ?0 :ans;
    }
};