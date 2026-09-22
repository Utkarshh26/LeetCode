class Solution {
    vector<vector<int>>dp;
    bool helper(int idx,int tar,vector<int>&nums){
        if(tar ==0){
            return true;
        }
        if(idx ==nums.size()-1){
            return nums[nums.size()-1] ==tar;
        }
        if(dp[idx][tar] !=-1){
            return dp[idx][tar];
        }
        bool notpick =helper(idx+1,tar,nums);
        bool pick =false;
        if(tar >= nums[idx]){
            pick =helper(idx+1,tar-nums[idx],nums);
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
        int tar = sum/2;
        dp.assign(nums.size(),vector<int>(tar+1,-1));
        return helper(0,tar,nums);
    }
};