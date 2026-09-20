class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> dp; 
        vector<int>points;
        int maxi = *max_element(nums.begin(),nums.end());
        points.resize(maxi+ 1,0);
        for (int x :nums){
            points[x]+=x;
        }
        dp.resize(maxi +2);
        dp[0]=0; dp[1]=points[0];

        for(int i=2; i<dp.size();i++){
            int taken= points[i-1]+dp[i-2];
            int leave=dp[i-1];
            dp[i] =max(taken,leave);
        }
        return dp.back();
    }
};