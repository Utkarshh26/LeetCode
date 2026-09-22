class Solution {
    vector<vector<int>>dp;
    bool helper(int idx,int tar,vector<int>&arr){
        if(tar ==0){
            return true;
        }
        if(idx ==0){
            return arr[0] ==tar;
        }
        if(dp[idx][tar] !=-1){
            return dp[idx][tar];
        }
        bool notpick =helper(idx-1,tar,arr);
        bool pick =false;
        if(tar >= arr[idx]){
            pick =helper(idx-1,tar-arr[idx],arr);
        }
        return dp[idx][tar]= notpick || pick;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int num : nums){
            sum += num;
        }
        if(sum%2){
            return false;
        }
        int tar = sum/2, n =nums.size();
        dp.assign(n,vector<int>(tar+1,-1));
        return helper(n-1,tar,nums);
    }
};