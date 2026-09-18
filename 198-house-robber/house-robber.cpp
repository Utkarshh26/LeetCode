class Solution {
    vector<int> dp;
private:    
    int helper(vector<int>&nums, int idx){
        if(idx >= nums.size()){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int steal= nums[idx] +helper(nums, idx+2);
        int skip = helper(nums,idx+1);
        return dp[idx] =max(steal, skip);
    }
public:
    int rob(vector<int>& nums) {
        dp.assign(nums.size(),-1);
        return helper(nums, 0);
    }
};