class Solution {
    int helper(int idx,int buy,int trn,vector<vector<vector<int>>>&dp,vector<int>&arr){
        if(trn == 0){
            return 0;
        }
        if(idx== arr.size()){
            return 0;
        }
        if(dp[idx][buy][trn] != -1){
            return dp[idx][buy][trn];
        }
        int profit =0;
        if(buy){
            profit= max(
                helper(idx+1,0,trn,dp,arr)-arr[idx],helper(idx+1,1,trn,dp,arr)
            );
        }else{
            profit= max(
                helper(idx+1,1,trn-1,dp,arr)+arr[idx],helper(idx+1,0,trn,dp,arr)
            );
        }
        return dp[idx][buy][trn]= profit;
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n =prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return helper(0,1,k,dp,prices);
    }
};