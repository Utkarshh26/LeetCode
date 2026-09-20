class Solution {
private:
    vector<int>points;
    vector<int> dp;
    int helper(int i) {
        if(i <= 0){
            return 0;
        } 
        if(dp[i]!= -1){
            return dp[i];
        }      

        int skip =helper(i -1);
        int take =points[i]+ helper(i- 2);
        return dp[i]= max(skip,take);
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        points.resize(maxi+ 1,0);
        for (int x :nums){
            points[x]+=x;
        }

        dp.resize(maxi +1,-1);
        return helper(maxi);
    }
};