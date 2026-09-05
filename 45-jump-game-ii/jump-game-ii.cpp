class Solution {
    vector<int> dp;
private:    
    int helper(vector<int>& nums, int idx){
        if(idx == nums.size()-1){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        int mini = 1e9;
        for(int i =1; i<=nums[idx] &&i+idx <nums.size();i++){
            int a = 1+helper(nums, idx+i);
            mini = min(mini, a);
        }
        return dp[idx] = mini;
    }
public:
    int jump(vector<int>& nums) {
        dp = vector<int>(nums.size(), -1);
        return helper(nums,0);
    }
};