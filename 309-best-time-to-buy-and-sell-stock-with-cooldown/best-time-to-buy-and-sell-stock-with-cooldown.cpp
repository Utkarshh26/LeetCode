class Solution {
private:
    int helper(int idx,int buy,vector<vector<int>>&dp,vector<int>&arr){
        if(idx>= arr.size()){
            return 0;
        }
        if(dp[idx][buy] != -1){
            return dp[idx][buy];
        }
        int profit =0;
        if(buy){
            profit= max(
                helper(idx+1,0,dp,arr)-arr[idx],helper(idx+1,1,dp,arr)
            );
        }else{
            profit= max(
                helper(idx+2,1,dp,arr)+arr[idx],helper(idx+1,0,dp,arr)
            );
        }
        return dp[idx][buy]= profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n =prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(0,1,dp,prices);
    }
};