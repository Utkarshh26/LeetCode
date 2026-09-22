class Solution {
    int helper(vector<vector<int>>&dp,vector<vector<int>>&grid,int row,int col){
        int m=grid.size()-1, n =grid[0].size()-1;
        if(row == m && (col >= 0 && col <= n)){
            return grid[row][col];
        }
        if(row >m || col< 0 || col >n){
            return INT_MAX;
        }
        if(dp[row][col] !=INT_MAX){
            return dp[row][col];
        }
        int down = helper(dp,grid,row+1,col);
        int leftdiag =helper(dp,grid,row+1,col-1);
        int rightdiag =helper(dp,grid,row+1,col+1);

        int mini = grid[row][col]+min(down,min(leftdiag,rightdiag));
        return dp[row][col]=mini;
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        int ans =INT_MAX;
        for(int i =0; i< n;i++){
            ans = min(ans,helper(dp,matrix,0,i));
        }
        return ans;
    }
};