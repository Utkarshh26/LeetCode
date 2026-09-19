class Solution {
    vector<int> dp;
private:
    int helper(vector<int>& nums,int idx, int n){
        if(idx >= n){
            return 0;
        }
        if(dp[idx]!= -1){
            return dp[idx];
        }
        int steal= nums[idx]+helper(nums, idx+2,n);
        int skip = helper(nums, idx+1,n); 
        return dp[idx]=max(steal,skip);
    }
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        if(n ==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        
        dp.assign(n,-1);
        int firststeal =helper(nums,0, n-1);
        dp.assign(n,-1);
        int firstskipped= helper(nums,1,n);
        return max(firststeal,firstskipped);
    }
};