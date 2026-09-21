class Solution {
private:    
    int helper(vector<vector<int>>&dp, int row, int col){
        int m= dp.size()-1, n =dp[0].size()-1;
        if(row == m&& col ==n){
            return 1;
        }
        if(row > m || col > n){
            return 0;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int down = helper(dp,row+1,col);
        int right = helper(dp, row, col+1);
        return dp[row][col] =down +right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return helper(dp,0,0);
    }
};