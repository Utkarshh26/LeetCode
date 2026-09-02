class Solution {
    vector<int>dp;
private:
    int helper(vector<int>& cost, int idx){
        if(idx >= cost.size()){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int ones = cost[idx] + helper(cost, idx+1);
        int twos = cost[idx] +helper(cost,idx+2);
        return dp[idx] = min(ones, twos);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        dp = vector<int> (cost.size(),-1);
        return min(helper(cost,0),helper(cost,1));
    }
};