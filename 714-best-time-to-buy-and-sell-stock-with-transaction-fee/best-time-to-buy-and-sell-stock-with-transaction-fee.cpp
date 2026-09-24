class Solution {
private:
    int helper(int idx,int buy,int& fee,vector<vector<int>>&dp,vector<int>&arr){
        if(idx >= arr.size()){
            return 0;
        }
        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }
        int profit =0;
        if(buy){
            profit= max(
                helper(idx+1,0,fee,dp,arr)-arr[idx],helper(idx+1,1,fee,dp,arr)
            );
        }else{
            profit= max(
                helper(idx+1,1,fee,dp,arr)+arr[idx]- fee,helper(idx+1,0,fee,dp,arr)
            );
        }
        return dp[idx][buy]= profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n =prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(0,1,fee,dp,prices);
    }
};