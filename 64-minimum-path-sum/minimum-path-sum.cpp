class Solution {
private:
    int helper(vector<vector<int>>&dp,vector<vector<int>>&grid,int row,int col){
        int m=grid.size()-1, n =grid[0].size()-1;
        if(row == m && col == n){
            return grid[row][col];
        }
        if(row > m || col >n){
            return INT_MAX;
        }
        if(dp[row][col] !=-1){
            return dp[row][col];
        }
        int down = helper(dp,grid,row+1,col);
        int right =helper(dp,grid,row,col+1);
        return dp[row][col] = grid[row][col]+ min(down,right);
    }
    
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m =grid.size(),n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return helper(dp,grid,0,0);
    }
};